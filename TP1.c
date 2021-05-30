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
    char* resultado = (char*)malloc(sizeof(char)*longitudCadena(cadena)+1);
    memcpy(resultado,cadena,sizeof(char)*longitudCadena(cadena)+1);
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

    char* resultado = (char*) malloc(sizeof(char));
    *resultado = '\0';

    char* aux = cadena;

    while(*aux !=  '\0'){        

        if (*aux != caracterEliminar){
            concatenar(resultado, &*aux);
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
    memcpy(concatenado, primerCadena, longitudCadena(primerCadena));
    memcpy(concatenado + longitudCadena(primerCadena), segundaCadena, longitudCadena(segundaCadena) + 1);
    return concatenado;
}

/* Punto 1F */
char *insertarEnPosicion(char *cadena, char caracter, int posicion)
{

    char *resultado;
    resultado = malloc(longitudCadena(cadena) + 2);

    memcpy(resultado, cadena, posicion - 1);
    memcpy(resultado + posicion - 1, &caracter, 1);
    memcpy(resultado + posicion, cadena + posicion - 1, longitudCadena(cadena) - posicion + 2);

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
    case 5:
        probarConcatenar();
        break;
    case 6:
        system(CLI_CLEAR);
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
    printf("\nTransformado a Mayuscula: %s", aMayuscula(cadena));
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
    printf("\nEl resultado es: %s", concatenar(cadena, otraCadena));
    
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
    printf("\nEl resultado es: %s", eliminarCaracter(cadena, caracter));

    presioneParaContinuar();

    return;
}

void probarInsertarEnPosicion()
{
    char cadena[tamanio];
    char caracter;
    int posicion;
    imprimirTitulo("Insertar caracter en posición");
    printf("Ingrese una cadena de caracteres: ");
    scanf("%s", cadena);
    vaciarInput();
    printf("Ingrese el caracter que desea insertar en la cadena: ");
    scanf("%c", &caracter);
    vaciarInput();
    printf("Ingrese la posicion donde desea insertarlo: ");
    scanf("%d", &posicion);
    vaciarInput();
    printf("\nEl resultado es: %s", insertarEnPosicion(cadena, caracter, posicion));

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