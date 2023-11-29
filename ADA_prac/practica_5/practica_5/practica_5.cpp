// practica_5.cpp : Matrices.
//

/* Hacer un algoritmo que:
	a) Almacene números aleatorios (menores o iguales a 10) en una matriz de 5 * 6.
	b) Recorra la matriz: mostrando sus elementos
	c) Imprima la suma de los números almacenados en la matriz.
	d) Imprima la suma de los números pares almacenados en la matriz
	e) Imprima la suma de los números impares almacenados en la matriz
	f) Imprima la suma de cada columnas
	g) Imprima la suma de cada fila
	h) Imprima la suma de los elementos de la diagonal principal
	i) Imprima la transpuesta de la matriz
	*/

#include <iostream>
#include <cstdlib>
#include <ctime>

#define FILAS 5
#define COLUMNAS 6
#define MAX_VALOR 10

using namespace std;

void llenarMatriz(int matriz[FILAS][COLUMNAS], int filas, int columnas);
void mostrarMatriz(int matriz[FILAS][COLUMNAS], int filas, int columnas);
int sumarElementosMatriz(int matriz[FILAS][COLUMNAS], int filas, int columnas);
int sumarParesMatriz(int matriz[FILAS][COLUMNAS], int filas, int columnas);
int sumarImparesMatriz(int matriz[FILAS][COLUMNAS], int filas, int columnas);
void mostrarSumaColumnas(int matriz[FILAS][COLUMNAS], int filas, int columnas);
void mostrarSumaFilas(int matriz[FILAS][COLUMNAS], int filas, int columnas);
void mostrarMatrizTranspuesta(int matriz[FILAS][COLUMNAS], int filas, int columnas);

int main() {
	srand(time(NULL));

	// Se declara la matriz
	int matriz[FILAS][COLUMNAS];
	int suma = 0;
	int sumaPares = 0;
	int sumaImpares = 0;
	int sumaDiagonalPrincipal = 0;

	// a) Almacene números aleatorios (menores que 100) en una matriz de 5 * 6. 
	llenarMatriz(matriz, FILAS, COLUMNAS);

	// b) Recorra la matriz: mostrando sus elementos
	mostrarMatriz(matriz, FILAS, COLUMNAS);

	// c) Imprima la suma de los números almacenados en la matriz
	suma = sumarElementosMatriz(matriz, FILAS, COLUMNAS);
	cout << "\nLa suma de los elementos de la matriz es: " << suma << endl;

	// d) Imprima la suma de los números pares almacenados en la matriz
	sumaPares = sumarParesMatriz(matriz, FILAS, COLUMNAS);
	cout << "\nLa suma de los numeros PARES de la matriz es: " << sumaPares << endl;

	// e) Imprima la suma de los números impares almacenados en la matriz
	sumaImpares = sumarImparesMatriz(matriz, FILAS, COLUMNAS);
	cout << "\nLa suma de los numeros IMPARES de la matriz es: " << sumaImpares << endl;

	// f) Imprima la suma de cada columnas
	mostrarSumaColumnas(matriz, FILAS, COLUMNAS);

	// g) Imprima la suma de cada fila
	mostrarSumaFilas(matriz, FILAS, COLUMNAS);

	// i) Imprima la transpuesta de la matriz
	mostrarMatrizTranspuesta(matriz, FILAS, COLUMNAS);
	return 0;
}

void llenarMatriz(int matriz[FILAS][COLUMNAS], int filas, int columnas) {
	for (int i = 0; i < filas; ++i) {
		for (int j = 0; j < columnas; ++j) {
			matriz[i][j] = rand() % (MAX_VALOR + 1); // números aleatorios menores o iguales a MAX_VALOR
		}
	}
}

void mostrarMatriz(int matriz[FILAS][COLUMNAS], int filas, int columnas) {
	cout << "La matriz es: " << endl;
	for (int i = 0; i < filas; ++i) {
		for (int j = 0; j < columnas; ++j) {
			cout << "\t" << matriz[i][j];
		}
		cout << endl;
	}
}

int sumarElementosMatriz(int matriz[FILAS][COLUMNAS], int filas, int columnas) {
	int suma = 0;
	for (int i = 0; i < filas; ++i) {
		for (int j = 0; j < columnas; ++j) {
			suma += matriz[i][j];
		}
	}
}

int sumarParesMatriz(int matriz[FILAS][COLUMNAS], int filas, int columnas) {
	int suma = 0;
	for (int i = 0; i < filas; ++i) {
		for (int j = 0; j < columnas; ++j) {
			if (matriz[i][j] % 2 == 0) {
				suma += matriz[i][j];
			}
		}
	}
}

int sumarImparesMatriz(int matriz[FILAS][COLUMNAS], int filas, int columnas) {
	int suma = 0;
	for (int i = 0; i < filas; ++i) {
		for (int j = 0; j < columnas; ++j) {
			if (matriz[i][j] % 2 != 0) {
				suma += matriz[i][j];
			}
		}
	}
}

void mostrarSumaColumnas(int matriz[FILAS][COLUMNAS], int filas, int columnas) {
	int suma = 0;
	cout << "\n";
	for (int j = 0; j < columnas; ++j) {
		suma = 0;
		for (int i = 0; i < filas; ++i) {
			suma += matriz[i][j];
		}
		cout << "La suma de la columna " << j << " es: " << suma << endl;
	}
}

void mostrarSumaFilas(int matriz[FILAS][COLUMNAS], int filas, int columnas) {
	int suma = 0;
	cout << "\n";
	for (int i = 0; i < filas; ++i) {
		suma = 0;
		for (int j = 0; j < columnas; ++j) {
			suma += matriz[i][j];
		}
		cout << "La suma de la fila " << i << " es: " << suma << endl;
	}
}

void mostrarMatrizTranspuesta(int matriz[FILAS][COLUMNAS], int filas, int columnas) {
	cout << "\nLa matriz transpuesta es: " << endl;
	for (int j = 0; j < columnas; ++j) {
		for (int i = 0; i < filas; ++i) {
			cout << "\t" << matriz[i][j];
		}
		cout << endl;
	}
}