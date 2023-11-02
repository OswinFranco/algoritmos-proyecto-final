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
int main() {
    int opcion;
    bool entradaValida = false;

    do {
        mostrarMenu();

        cout << "Ingrese la opcion deseada (del 1 al 7): ";

        if (cin >> opcion) {
            entradaValida = (opcion >= 1 && opcion <= 7);
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            entradaValida = false;
        }
