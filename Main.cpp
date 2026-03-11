#include <iostream>
#include "triangulo.h" // <--- AQUÍ LO MENCIONAS PARA PODER USAR LA CLASE

int main() {
    // Aquí es donde creas el objeto y pides los datos
    Triangulo miTri(10.5, 5.0);
    std::cout << "El area es: " << miTri.calcularArea();
    return 0;
}
