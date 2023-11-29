// practica_6.cpp : Algoritmo de Backtracking aplicado al problema de las N Reinas


#include <iostream>

class Solucion {
public:
    Solucion(int N) : tablero(N, vector<int>(N, 0)), N(N) {}

    void imprimir() const {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cout << (tablero[i][j] ? "Q" : ".");
            }
            cout << endl;
        }
    }

    vector<vector<int>> tablero;
    int N;
};

class Candidatos {
public:
    Candidatos(int N) : disponibles(N, true) {}

    vector<int> obtener() const {
        vector<int> candidatos;
        for (int i = 0; i < disponibles.size(); ++i) {
            if (disponibles[i]) {
                candidatos.push_back(i);
            }
        }
        return candidatos;
    }

    void marcar(int pos) {
        disponibles[pos] = false;
    }

    void desmarcar(int pos) {
        disponibles[pos] = true;
    }

private:
    vector<bool> disponibles;
};

class Solucionador {
public:
    Solucionador(int N) : N(N) {}

    bool resolverNReinas(Solucion& solucion, int fila) {
        if (fila == N) {
            return true;  // Todas las reinas están colocadas
        }

        Candidatos candidatos(N);
        vector<int> cands = candidatos.obtener();

        for (int columna : cands) {
            if (esSeguro(solucion, fila, columna)) {
                solucion.tablero[fila][columna] = 1;
                candidatos.marcar(columna);

                if (resolverNReinas(solucion, fila + 1)) {
                    return true;
                }

                candidatos.desmarcar(columna);
                solucion.tablero[fila][columna] = 0;  // Retroceder si no se encuentra solución
            }
        }

        return false;  // No se encontró una posición segura para colocar la reina en esta fila
    }

private:
    bool esSeguro(const Solucion& solucion, int fila, int columna) const {
        for (int i = 0; i < fila; ++i) {
            if (solucion.tablero[i][columna] == 1) {
                return false;
            }
        }

        for (int i = fila, j = columna; i >= 0 && j >= 0; --i, --j) {
            if (solucion.tablero[i][j] == 1) {
                return false;
            }
        }

        for (int i = fila, j = columna; i >= 0 && j < N; --i, ++j) {
            if (solucion.tablero[i][j] == 1) {
                return false;
            }
        }
    }

    int N;
};

int main() {
    int N;
    cout << "Ingrese el tamano del tablero (N): ";
    cin >> N;

    Solucion solucion(N);
    Solucionador solucionador(N);

    if (solucionador.resolverNReinas(solucion, 0)) {
        cout << "Solucion encontrada:" << endl;
        solucion.imprimir();
    }
    else {
        cout << "No se encontro solución para N = " << N << endl;
    }

    return 0;
}