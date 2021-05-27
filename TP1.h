#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

int longitudCadena (char* cadena);
int convertirCadenaADigitos(char* cadena);
char* aMayuscula(char* cadena);
char* eliminarCaracter(char* cadena, char caracter);
char* concatenar(char *primerCadena, char *segundaCadena);
char* insertarEnPosicion(char *cadena, char caracter, int posicion);
void* plegarCadena(char* cadena,  void*(*mutacion)(char*,void*));