#include <iostream>
#include <fstream>
#include <string>
#include <limits>
using namespace std;

const char *nombre_archivo = "diccionario.dat";

struct diccionario {
    char palabra[500];
    char traduccion[500];
    char funcionalidad[500];
};

void leer();
void crear();
void actualizar();
void borrar();
void traducirCodigo();
void mostrarMenu(