#include "vector.h"
#include <iostream>

using namespace std;

vector::vector(void) {
	n = 0;
}

vector::~vector(void) {
}

void vector::cargarVector(int vec[], int n) {
	for (int i = 0; i < n; i++) {
		cout << "vec[" << i << "] = ";
		cin >> vec[i];
	}
}

void vector::mostrarVector(int vec[], int n) {
	for (int i = 0; i < n; i++) {
		cout << vec[i] << (i == n - 1 ? "" : ", ");
	}
	cout << endl;
}

void vector::ordenarVector(int vec[], int n) {
	int aux;
	for (int i = 0; i < (n - 1); i++) {
		for (int j = i + 1; j < n; j++) {
			if (vec[i] > vec[j]) {
				aux = vec[i];
				vec[i] = vec[j];
				vec[j] = aux;
			}
		}
	}
}

// NUEVA LÓGICA DE CONCATENACIÓN
void vector::concatenarVector(int v1[], int n, int v2[], int m, int resultado[]) {
	// Copiar el primer vector
	for (int i = 0; i < n; i++) {
		resultado[i] = v1[i];
	}
	// Copiar el segundo vector justo después
	for (int j = 0; j < m; j++) {
		resultado[n + j] = v2[j];
	}
}
