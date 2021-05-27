#include "TP1.h"


int main()
{
    while( 1 ){
        mostrarMenu();
    }

	return 0;
}

/* Punto 1A */
int longitudCadena (char* cadena)
{
    int contador = 0;

    while (cadena[contador] != '\0')
    {
        contador++;
    }

    return contador;
}

/* Punto 1B */
int convertirCadenaADigitos(char* cadena) {

    void* _aDigitos(char* caracter, void* acum){

        int numero = *(int*)acum;
        return numero * 10 + (caracter - '0');
    }   

    return *(int*)plegarCadena(cadena,_aDigitos);
}

/* Punto 1C */
char* aMayuscula(char* cadena){

    void* _aMayuscula(char* caracter, void* acum){

        if (*caracter >='a' && *caracter<='z'){
            return (void*) concatenar((char*)acum,caracter-32);
        }

        return concatenar((char*)acum,caracter);
    }   

    return (char*)plegarCadena(cadena,_aMayuscula);

}

/* Punto 1D */
char* eliminarCaracter(char* cadena, char caracter){

    void* _eliminarCaracter(char* _caracter, void* acum){
      
        if (*_caracter  != caracter){
            return (void*)concatenar((char*)acum,_caracter);
        }

        return acum;
    }   

    return (char*)plegarCadena(cadena,_eliminarCaracter);

}

/* Punto 1E */
char* concatenar(char *primerCadena, char *segundaCadena){
    char *concatenado;
    concatenado = malloc(longitudCadena(primerCadena) + longitudCadena(segundaCadena) + 1);
    memcpy(concatenado, primerCadena, longitudCadena(primerCadena));
    memcpy(concatenado + longitudCadena(primerCadena), segundaCadena, longitudCadena(segundaCadena)+1);
    return concatenado;
}

/* Punto 1F */
char* insertarEnPosicion(char *cadena, char caracter, int posicion){

    char *resultado;
    resultado = malloc( longitudCadena(cadena) + 2);

    memcpy( resultado, cadena, posicion -1);
    memcpy( resultado + posicion -1, &caracter, 1);
    memcpy( resultado + posicion, cadena + posicion -1, longitudCadena(cadena)-posicion+2);

    return resultado;

}

/* Punto 2*/

void mostrarMenu()
{
    printf("Ingrese la opcion de la funcion que quiere probar:\n");
    printf("1 - obtenerLongitud\n");
    printf("2 - cadenaANumeros\n");
    printf("3 - cadenaAMayusculas\n");
    printf("? - Salir\n");
    int eleccion;
    scanf("%d", &eleccion);
    switch (eleccion)
    {
    case 1:
        probarObtenerLongitud();
        break;
    case 2:
        probarCadenaANumeros();
        break;
    case 3:
        probarCadenaAMayusculas();
        break;
    case 5:
        probarConcatenarCadenas();
        break;
    default:
        printf("gracias por usar... saliendo...")
        exit(0);
        break;
    }
}

/* Aux */
void* plegarCadena(char* cadena, void*(*mutacion)(char*,void*)){

    char* aux = cadena;
    void* acumulador;
    
    while (*aux != '\0'){    
        void* auxAcum = mutacion(aux,acumulador);
        free(acumulador);
        acumulador = auxAcum;
        aux ++;
    }

    return acumulador;
}