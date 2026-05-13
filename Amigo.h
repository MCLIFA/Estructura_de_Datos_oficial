#pragma once
#ifndef AMIGO_H
#define AMIGO_H

#include <iostream>
#include <fstream>
#include <string>

// La clase Amigo define la estructura del objeto y sus capacidades
class Amigo {
private:
    // Atributos (Datos privados)
    std::string nombre;
    int edad;
    char sexo;
    char estado; // 'E' para eliminado, 'A' para activo

public:
    // Constructores
    Amigo();
    Amigo(std::string nom, int ed, char sx);

    // Métodos de acceso (Setters y Getters)
    void setAmigo(std::string nom, int ed, char sx);
    std::string getNombre();
    int getEdad();
    char getSexo();
    char getEstado();

    // Métodos de persistencia (Archivos)
    void guardarArchivo(std::ofstream& fsalida);
    bool leerArchivo(std::ifstream& fentrada);
    bool eliminar(std::fstream& fes, int nroReg);
    bool modificar(std::fstream& fes, int nroReg);
    bool buscar(std::ifstream& fentrada, int nroReg);

    // Método auxiliar para el manejo de posiciones en el archivo
    int getTamBytesRegistro();
};

#endif
