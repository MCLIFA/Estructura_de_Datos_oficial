#include "ABMamigo.h"
#include <iostream>
#include <fstream>
#include <limits> // Necesario para limpiar el buffer de entrada

using namespace std;

// Constructor: Inicializa el nombre del archivo y el puntero
ABMamigo::ABMamigo(string nomArch) {
    nomArchivo = nomArch;
    amig = nullptr;
}

// Método para pedir datos por teclado
void ABMamigo::introducirDatos(Amigo* newReg) {
    string nombre;
    int edad;
    char sexo;

    cout << "\n\nIntroducir los siguientes datos --->>> :" << endl;

    // Limpieza de buffer: evita que el getline se salte al leer el nombre
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Nombre : ";
    getline(cin, nombre);

    cout << "Edad   : ";
    cin >> edad;

    cout << "Sexo <F/M>: ";
    cin >> sexo;

    // Seteamos los datos en el objeto Amigo
    newReg->setAmigo(nombre, edad, sexo);
}

// Muestra los datos de un amigo en una sola línea
void ABMamigo::mostrarRegistro(int nroReg) {
    cout << endl << nroReg << ".-  " << amig->getNombre()
        << "  " << amig->getEdad()
        << "  " << amig->getSexo()
        << "  " << amig->getEstado();
}

// Crea un amigo, pide datos y lo guarda al final del archivo
void ABMamigo::adicionarNuevo() {
    ofstream fsalida(nomArchivo, ios::app | ios::binary);
    amig = new Amigo();

    introducirDatos(amig);
    amig->guardarArchivo(fsalida);

    fsalida.close();
    delete amig; // Liberamos memoria
}

// Lee todo el archivo y muestra solo los que no están eliminados ('A')
void ABMamigo::listar() {
    int cr = 0;
    cout << "\n\nLos registros son --->>> : " << endl;
    amig = new Amigo();
    ifstream fentrada(nomArchivo, ios::in | ios::binary);

    while (amig->leerArchivo(fentrada)) {
        cr++;
        if (amig->getEstado() == 'A') {
            mostrarRegistro(cr);
        }
    }

    fentrada.close();
    delete amig;
}

// Busca un registro por su posición física (1, 2, 3...)
int ABMamigo::buscarReg() {
    int nroReg;
    cout << "\n\nIntroducir numero de registro a buscar : ";
    cin >> nroReg;

    amig = new Amigo();
    ifstream fentrada(nomArchivo, ios::in | ios::binary);

    if (amig->buscar(fentrada, nroReg)) {
        mostrarRegistro(nroReg);
    }
    else {
        cout << "\nRegistro no existe.";
        nroReg = -1;
    }

    fentrada.close();
    // No hacemos delete aquí porque eliminarReg y modificarReg usan este objeto
    return nroReg;
}

// Marca un registro como eliminado ('E')
void ABMamigo::eliminarReg() {
    int nroReg = buscarReg();
    if (nroReg > 0) {
        fstream fes(nomArchivo, ios::in | ios::out | ios::binary);
        if (amig->eliminar(fes, nroReg)) {
            cout << "\nRegistro eliminado correctamente." << endl;
        }
        fes.close();
    }
    delete amig;
}

// Cambia los datos de un registro existente
void ABMamigo::modificarReg() {
    int nroReg = buscarReg();
    if (nroReg > 0) {
        fstream fes(nomArchivo, ios::in | ios::out | ios::binary);
        cout << "\n--- Ingrese los nuevos datos ---";
        introducirDatos(amig);

        if (amig->modificar(fes, nroReg)) {
            cout << "\nRegistro modificado correctamente." << endl;
        }
        fes.close();
    }
    delete amig;
}
