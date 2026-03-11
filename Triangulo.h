#pragma once // Esto le dice a Visual Studio que solo lea este archivo una vez

class Triangulo {
private:
    double base;
    double altura;

public:
    Triangulo(double b, double a); // Prototipo del constructor
    double calcularArea();         // Prototipo del método
};
