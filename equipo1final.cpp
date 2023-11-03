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
if (!entradaValida) {
            cout << "Entrada no valida. Ingrese un numero entre 1 y 7." << endl;
        } else {
            switch (opcion) {
                 case 1:
           			 crear();
           			 break;
       			 case 2:
           			 leer();
           			 break;
      			 case 3:
           			 actualizar();
           			 break;
                 case 4:
          			  borrar();
          			  break;
          		 case 5:
         			 system("cls || clear");
                     break;
       			 case 6:
         			 traducirCodigo();
           			 break;
                 case 7:
                	cout << "Saliendo del programa." << endl;
                    break;                    
            }
        }
    } while (opcion != 7);

    return 0;
}
void mostrarMenu(){
    cout<<""Menu:\n1. Agregar Palabra\n2. Ver Palabras\n3. Actualizar Palabra\n4. Borrar Palabra\n5. Limpiar\n6. Traducir\n7. Salir\n";
}
void leer() {
      system("cls");
    FILE *archivo = fopen(nombre_archivo, "rb");
    if (!archivo) {
        archivo = fopen(nombre_archivo, "w+b");
    }
    diccionario diccionario;
    int id = 0;
    fread(&diccionario, sizeof(diccionario), 1, archivo);
    cout << "__________________________________" << endl;
    cout << "id" << " | " << "   Palabra:   " << " | " << "Traduccion: " << " | " << "Funcionalidad: " << endl;
    do {
        cout << id << "    | " << diccionario.palabra << " | " << diccionario.traduccion << " | " << diccionario.funcionalidad << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        
        fread(&diccionario, sizeof(diccionario), 1, archivo);
        id += 1;
    } while (feof(archivo) == 0);
    fclose(archivo);
}
void crear() {
    FILE *archivo = fopen(nombre_archivo, "a+b");
    char res;
    diccionario diccionario;
    do {
        fflush(stdin);
        cout << "Ingrese Palabra: ";
        cin >> diccionario.palabra;
        cin.ignore();

        cout << "Ingrese Traduccion: ";
        cin.getline(diccionario.traduccion, 500);

        cout << "Ingrese Funcionalidad: ";
        cin.getline(diccionario.funcionalidad, 500);

        fwrite(&diccionario, sizeof(diccionario), 1, archivo);
        cout << "Desea agregar otra palabra (s/n): ";
        cin >> res;

    } while (res == 's' || res == 'S');
    fclose(archivo);
}
void actualizar() {
     FILE *archivo = fopen(nombre_archivo, "r+b");
    diccionario diccionario;
    int id = 0;
    cout << "Ingrese el ID que desea actualizar: ";
    cin >> id;
    fseek(archivo, id * sizeof(diccionario), SEEK_SET);

    cout << "Ingrese la palabra: ";
    cin >> diccionario.palabra;
    cin.ignore();

    cout << "Ingrese Traduccion: ";
    cin.getline(diccionario.traduccion, 50);

    cout << "Ingrese Funcionalidad: ";
    cin.getline(diccionario.funcionalidad, 50);

    fwrite(&diccionario, sizeof(diccionario), 1, archivo);

    fclose(archivo);
    leer();
}

void borrar() {
     const char *nombre_archivo_temp = "archivo_temp.dat";
    FILE *archivo_temp = fopen(nombre_archivo_temp, "w+b");
    FILE *archivo = fopen(nombre_archivo, "rb");
    diccionario diccionario;
    int id = 0, id_n = 0;
    cout << "Ingrese el ID a eliminar: ";
    cin >> id;

    while (fread(&diccionario, sizeof(diccionario), 1, archivo)) {
        if (id_n != id) {
            fwrite(&diccionario, sizeof(diccionario), 1, archivo_temp);
            id_n++;
        }
    }

    fclose(archivo);
    fclose(archivo_temp);

    archivo_temp = fopen(nombre_archivo_temp, "rb");
    archivo = fopen(nombre_archivo, "wb");
    while (fread(&diccionario, sizeof(diccionario), 1, archivo_temp)) {
        fwrite(&diccionario, sizeof(diccionario), 1, archivo);
    }

    fclose(archivo);
    fclose(archivo_temp);
    leer();
}
