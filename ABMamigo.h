#ifndef ABMAMIGO_H
#define ABMAMIGO_H

#include "Amigo.h"
#include <string>

class ABMamigo {
private:
    std::string nomArchivo;
    Amigo* amig; // Puntero para manipular objetos de la clase Amigo

public:
    ABMamigo(std::string nomArch);

    // Métodos que interactúan con el usuario (cin/cout)
    void introducirDatos(Amigo* newReg);
    void mostrarRegistro(int nroReg);

    // Operaciones del CRUD (Crear, Leer, Actualizar, Borrar)
    void adicionarNuevo();
    void listar();
    int buscarReg();
    void eliminarReg();
    void modificarReg();
};

#endif
