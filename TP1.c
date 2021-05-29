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
    void *_aDigitos(char *caracter, void *acum)
    {

        int numero = *(int *)acum;
        return numero * 10 + (caracter - '0');
    }
    return *(int *)plegarCadena(cadena, _aDigitos);
}

/* Punto 1C */
char *aMayuscula(char *cadena)
{

    void *_aMayuscula(char *caracter, void *acum)
    {

        if (*caracter >= 'a' && *caracter <= 'z')
        {
            return (void *)concatenar((char *)acum, caracter - 32);
        }

        return concatenar((char *)acum, caracter);
    }

    return (char *)plegarCadena(cadena, _aMayuscula);
}

/* Punto 1D */
char *eliminarCaracter(char *cadena, char caracter)
{

    void *_eliminarCaracter(char *_caracter, void *acum)
    {

        if (*_caracter != caracter)
        {
            return (void *)concatenar((char *)acum, _caracter);
        }

        return acum;
    }

    return (char *)plegarCadena(cadena, _eliminarCaracter);
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
    printf("Ingrese la opcion de la funcion que quiere probar:\n");
    printf("1 - obtenerLongitud\n");
    printf("2 - convertirCadenaADigitos\n");
    printf("3 - aMayuscula \n");
    printf("4 - eliminarCaracter\n");
    printf("5 - concatenar \n");
    printf("6 - insertarEnPosicion \n");
    printf("7 - Salir \n");
    int eleccion;
    scanf("%d", &eleccion);
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

/* Aux */
void *plegarCadena(char *cadena, void *(*mutacion)(char *, void *))
{

    char *aux = cadena;
    void *acumulador;

    while (*aux != '\0')
    {
        void *auxAcum = mutacion(aux, acumulador);
        free(acumulador);
        acumulador = auxAcum;
        aux++;
    }

    return acumulador;
}

/*Tests*/

void probarLongitudCadena()
{
    printf("Ingrese una cadena de caracteres: \n");
    char cadena[tamanio];
    scanf("%s", cadena);
    int longitud = longitudCadena(cadena);
    printf("La longitud de la cadena ingresada es: %d", longitud);
    return;
}

void probarConvertirCadenaADigitos()
{
    printf("Ingrese una cadena de caracteres: \n");
    char cadena[tamanio];
    scanf("%s", cadena);
    int cadenaConvertida = convertirCadenaADigitos(cadena);
    printf("El equivalente numerico de la cadena ingresada es: %d", cadenaConvertida);
    return;
}

void probarAMayuscula()
{
    printf("Ingrese una cadena de caracteres: \n");
    char cadena[tamanio];
    scanf("%s", cadena);
    printf("Transformado a Mayuscula: %s", aMayuscula(cadena));
}

void probarConcatenar()
{
    char cadena[tamanio];
    char otraCadena[tamanio];
    printf("Ingrese una cadena de caracteres: \n");
    scanf("%s", cadena);
    printf("Ingrese otra cadena de caracteres: \n");
    scanf("%s", otraCadena);
    printf("%s", concatenar(cadena, otraCadena));
    return;
}

void probarEliminarCaracter()
{
    char cadena[tamanio];
    char caracter;
    printf("Ingrese una cadena de caracteres: \n");
    scanf("%s", cadena);
    printf("Ingrese el caracter que desea eliminar de la cadena: \n");
    scanf("%c", &caracter);
    printf("%s", eliminarCaracter(cadena, caracter));
    return;
}

void probarInsertarEnPosicion()
{
    char cadena[tamanio];
    char caracter;
    int posicion;
    printf("Ingrese una cadena de caracteres: \n");
    scanf("%s", cadena);
    printf("Ingrese el caracter que desea insertar en la cadena: \n");
    scanf("%c", &caracter);
    printf("Ingrese la posicion donde desea insertarlo: \n");
    scanf("%d", &posicion);
    printf("%s", insertarEnPosicion(cadena, caracter, posicion));
    return;
}