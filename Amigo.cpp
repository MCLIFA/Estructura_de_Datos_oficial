#include "Amigo.h"

using namespace std;

// Constructor por defecto
Amigo::Amigo() {
    nombre = "";
    edad = 0;
    sexo = ' ';
    estado = ' ';
}

// Constructor con parámetros
Amigo::Amigo(string nom, int ed, char sx) {
    nombre = nom;
    edad = ed;
    sexo = sx;
    estado = 'A'; // Por defecto activo
}

void Amigo::setAmigo(string nom, int ed, char sx) {
    nombre = nom;
    edad = ed;
    sexo = sx;
    estado = 'A';
}

// Getters
string Amigo::getNombre() { return nombre; }
int Amigo::getEdad() { return edad; }
char Amigo::getSexo() { return sexo; }
char Amigo::getEstado() { return estado; }

// Importante: Calcula el tamaño de los datos para el archivo binario
int Amigo::getTamBytesRegistro() {
    return (sizeof(nombre) + sizeof(edad) + sizeof(sexo) + sizeof(estado));
}

void Amigo::guardarArchivo(ofstream& fsalida) {
    fsalida.write(reinterpret_cast<char*>(&nombre), sizeof(nombre));
    fsalida.write(reinterpret_cast<char*>(&edad), sizeof(edad));
    fsalida.write(reinterpret_cast<char*>(&sexo), sizeof(sexo));
    fsalida.write(reinterpret_cast<char*>(&estado), sizeof(estado));
}

bool Amigo::leerArchivo(ifstream& fentrada) {
    if (fentrada.is_open()) {
        fentrada.read(reinterpret_cast<char*>(&nombre), sizeof(nombre));
        if (!fentrada.eof()) {
            fentrada.read(reinterpret_cast<char*>(&edad), sizeof(edad));
            fentrada.read(reinterpret_cast<char*>(&sexo), sizeof(sexo));
            fentrada.read(reinterpret_cast<char*>(&estado), sizeof(estado));
            return true;
        }
    }
    return false;
}

bool Amigo::eliminar(fstream& fes, int nroReg) {
    // Primero buscamos si existe
    if (buscar(reinterpret_cast<ifstream&>(fes), nroReg)) {
        estado = 'E'; // Cambiamos el estado a Eliminado
        // Nos posicionamos para sobreescribir solo ese registro
        fes.seekp(getTamBytesRegistro() * (nroReg - 1), ios::beg);
        guardarArchivo(reinterpret_cast<ofstream&>(fes));
        return true;
    }
    return false;
}

bool Amigo::modificar(fstream& fes, int nroReg) {
    string nomAux = nombre; // Guardamos el nombre que ya seteamos afuera
    fes.seekg(getTamBytesRegistro() * (nroReg - 1), ios::beg);

    // Verificamos que el registro exista antes de sobreescribir
    char temp[100];
    if (fes.read(temp, sizeof(nombre))) {
        nombre = nomAux;
        estado = 'A';
        fes.seekp(getTamBytesRegistro() * (nroReg - 1), ios::beg);
        guardarArchivo(reinterpret_cast<ofstream&>(fes));
        return true;
    }
    return false;
}

bool Amigo::buscar(ifstream& fentrada, int nroReg) {
    if (fentrada.is_open()) {
        fentrada.seekg(getTamBytesRegistro() * (nroReg - 1), ios::beg);
        fentrada.read(reinterpret_cast<char*>(&nombre), sizeof(nombre));
        fentrada.read(reinterpret_cast<char*>(&edad), sizeof(edad));
        fentrada.read(reinterpret_cast<char*>(&sexo), sizeof(sexo));
        fentrada.read(reinterpret_cast<char*>(&estado), sizeof(estado));
        return !fentrada.eof();
    }
    return false;
}
