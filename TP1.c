#include "TP1.h"

int main()
{

    while (1)
    {
        mostrarMenu();
    }

    return 0;
}

/* Punto 1A */
int longitudCadena(char *cadena)
{
    int contador = 0;

    while (cadena[contador] != '\0')
    {
        contador++;
    }

    return contador;
}

/* Punto 1B */
int convertirCadenaADigitos(char *cadena)
{

    int numero = 0;
    int signo = 1;
    char* aux = cadena;

    if(*aux == '-') {
        signo = -1; 
        aux++;
    }

    while(*aux !=  '\0'){
        if(*aux < '0' || *aux > '9'){
            imprimirError("\nEl numero ingresado no es valido\n");
            return -1;
        }
        numero = numero * 10 + (*aux - '0');
        aux++;
    }
    
    return numero * signo; 
}

/* Punto 1C */
char *aMayuscula(char *cadena)
{
    char* resultado = crearCadena(cadena);
    char* aux = resultado;
    
    while(*aux !=  '\0'){
        if (*aux >= 'a' && *aux <= 'z')
        {
            *aux = *aux -32;
        }
        aux++;
    }

    return resultado;
}

/* Punto 1D */
char *eliminarCaracter(char *cadena, char caracterEliminar)
{

    char* resultado = crearCadena(NULL);
    char* aux = cadena;

    while(*aux != '\0'){        

        if (*aux != caracterEliminar){
            char* concatenado = insertarEnPosicion(resultado, *aux, longitudCadena(resultado)+1);
            free(resultado);
            resultado = concatenado;
        }

        aux++;

    }

    return resultado;

}

/* Punto 1E */
char *concatenar(char *primerCadena, char *segundaCadena)
{
    char *concatenado;
    concatenado = malloc(longitudCadena(primerCadena) + longitudCadena(segundaCadena) + 1);
    copiarMemoria(concatenado, primerCadena, longitudCadena(primerCadena));
    copiarMemoria(concatenado + longitudCadena(primerCadena), segundaCadena, longitudCadena(segundaCadena) + 1);
    return concatenado;
}

/* Punto 1F */
char *insertarEnPosicion(char *cadena, char caracter, int posicion)
{
    
    if(posicion > longitudCadena(cadena) + 1 || posicion < 0){
        imprimirError("\nLa posicion ingresada no es valida\n");         
        return crearCadena("-1");
    }

    char *resultado;
    resultado = (char*) malloc(sizeof(char)* longitudCadena(cadena) + 2);

    copiarMemoria(resultado, cadena, posicion - 1);
    copiarMemoria(resultado + posicion - 1, &caracter, 1);
    copiarMemoria(resultado + posicion, cadena + posicion - 1, longitudCadena(cadena) - posicion + 2);

    return resultado;
}

/* Punto 2*/

void mostrarMenu()
{
    system(CLI_CLEAR);
    imprimirTitulo("Ingrese la opcion de la funcion que quiere probar:");
    printf("1 - obtenerLongitud\n");
    printf("2 - convertirCadenaADigitos\n");
    printf("3 - aMayuscula \n");
    printf("4 - eliminarCaracter\n");
    printf("5 - concatenar \n");
    printf("6 - insertarEnPosicion \n");
    printf("7 - Salir \n");
    printf("\nSeleccion: ");
    int eleccion;
    scanf("%d", &eleccion);
    vaciarInput();
    system(CLI_CLEAR);
    switch (eleccion)
    {
    case 1:
        probarLongitudCadena();
        break;
    case 2:
        probarConvertirCadenaADigitos();
        break;
    case 3:
        probarAMayuscula();
        break;
    case 4:
        probarEliminarCaracter();
        break;
    case 5:
        probarConcatenar();
        break;
    case 6:
        probarInsertarEnPosicion();
        break;
    case 7:
        printf("Saliendo... \n");
        exit(0);
        break;
    default:
        printf("Ingrese una opcion valida \n");
        break;
    }
    printf("\n \n");
}

/*Tests*/

void probarLongitudCadena()
{
    imprimirTitulo("Longitud de cadena");
    printf("Ingrese una cadena de caracteres: ");
    char cadena[tamanio];
    scanf("%s", cadena);
    vaciarInput();
    int longitud = longitudCadena(cadena);
    printf("\nLa longitud de la cadena ingresada es: %d", longitud);
    presioneParaContinuar();
    return;
}

void probarConvertirCadenaADigitos()
{
    imprimirTitulo("Convertir cadena a digitos");

    printf("Ingrese una cadena de caracteres: ");
    char cadena[tamanio];
    scanf("%s", cadena);
    vaciarInput();
    int cadenaConvertida = convertirCadenaADigitos(cadena);
    printf("\nEl resultado es: %d", cadenaConvertida);
    presioneParaContinuar();
    return;
}

void probarAMayuscula()
{
    imprimirTitulo("Convertir cadena a mayuscula");
    printf("Ingrese una cadena de caracteres: ");
    char cadena[tamanio];
    scanf("%s", cadena);
    vaciarInput();
    char* resultado = aMayuscula(cadena);
    printf("\nTransformado a Mayuscula: %s", resultado);
    free(resultado);

    presioneParaContinuar();
}

void probarConcatenar()
{
    char cadena[tamanio];
    char otraCadena[tamanio];
    imprimirTitulo("Concatenar cadenas");
    printf("Ingrese una cadena de caracteres: ");
    scanf("%s", cadena);
    vaciarInput();
    printf("Ingrese otra cadena de caracteres: ");
    scanf("%s", otraCadena);
    vaciarInput();
    char* resultado = concatenar(cadena, otraCadena);
    printf("\nEl resultado es: %s", resultado);
    free(resultado);
    
    presioneParaContinuar();

    return;
}

void probarEliminarCaracter()
{
    char cadena[tamanio];
    char caracter;
    imprimirTitulo("Eliminar caracter");
    printf("Ingrese una cadena de caracteres: ");
    scanf("%s", cadena);
    vaciarInput();
    printf("Ingrese el caracter que desea eliminar de la cadena: ");
    scanf("%c", &caracter);
    vaciarInput();
    char* resultado = eliminarCaracter(cadena, caracter);
    printf("\nEl resultado es: %s", resultado);
    free(resultado);

    presioneParaContinuar();

    return;
}

void probarInsertarEnPosicion()
{
    char cadena[tamanio];
    char caracter;
    int posicion;
    imprimirTitulo("Insertar caracter en posici??n");
    printf("Ingrese una cadena de caracteres: ");
    scanf("%s", cadena);
    vaciarInput();
    printf("Ingrese el caracter que desea insertar en la cadena: ");
    scanf("%c", &caracter);
    vaciarInput();
    printf("Ingrese la posicion donde desea insertarlo: ");
    scanf("%d", &posicion);
    vaciarInput();
    char* resultado = insertarEnPosicion(cadena, caracter, posicion);
    printf("\nEl resultado es: %s", resultado);
    free(resultado);

    presioneParaContinuar();

    return;
}

/* Auxiliares */
void imprimirTitulo(char* titulo){
    printf("\033[0;32m");
    printf("%s\n\n",titulo);
    printf("\033[0m");
}

void imprimirError(char* error){
    printf("\033[0;31m");
    printf("%s",error);
    printf("\033[0m");
}

void presioneParaContinuar(){
    printf("\n\nPresione una tecla para continuar...");
    fgetc(stdin);
}

void vaciarInput(){
    while ((getchar()) != '\n');
}

char* crearCadena(char* contenido){

    char* _crearCadenaVacia(){
        char* resultado = (char*) malloc(sizeof(char));
        *resultado = '\0'; 
        return resultado;
    }

    if(contenido == NULL){
        return _crearCadenaVacia();
    }

    char* cadenaVacia = _crearCadenaVacia();
    char* cadena = concatenar(cadenaVacia,contenido);
    free(cadenaVacia);
    return cadena;
}

void copiarMemoria(void *destino, void *origen, int cantidadBytes){

   char *cadenaOrigen = (char*)origen;
   char *cadenaDestino = (char*)destino; 

   for (int i=0; i<cantidadBytes; i++)
       cadenaDestino[i] = cadenaOrigen[i];
}