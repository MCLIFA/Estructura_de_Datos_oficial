#include "triangulo.h" // <--- AQUÍ LO MENCIONAS

// Ahora ya puedes definir qué hace cada función
Triangulo::Triangulo(double b, double a) {
    base = b;
    altura = a;
}

double Triangulo::calcularArea() {
    return (base * altura) / 2;
}
