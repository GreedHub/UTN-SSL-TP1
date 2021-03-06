#include <stdio.h>
#include <stdlib.h>

#define tamanio 51 //Los arrays seran de maximo 50 caracteres + el \0

#ifdef _WIN32
 #define CLI_CLEAR "cls"
#else
 #define CLI_CLEAR "clear"
#endif

/* Funciones */
int longitudCadena(char *cadena);
int convertirCadenaADigitos(char *cadena);
char *aMayuscula(char *cadena);
char *eliminarCaracter(char *cadena, char caracter);
char *concatenar(char *primerCadena, char *segundaCadena);
char *insertarEnPosicion(char *cadena, char caracter, int posicion);

/* Pruebas */
void mostrarMenu();
void probarLongitudCadena();
void probarConvertirCadenaADigitos();
void probarAMayuscula();
void probarEliminarCaracter();
void probarConcatenar();
void probarInsertarEnPosicion();

/* Auxiliares */
void imprimirTitulo(char* titulo);
void presioneParaContinuar();
void vaciarInput();
void imprimirError(char* error);
char* crearCadena(char* contenido);
void copiarMemoria(void *destino, void *origen, int cantidadBytes);