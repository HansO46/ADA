// practica_4.cpp : Invertir el orden de los elementos de un vector
//

#include <iostream>

void invertir_orden_vector(int v, int num)
{
    for (int i = 0; i < num / 2; ++i)  // Se recorre el vector hasta la mitad
    {
        int aux = v[i];
        v[i] = v[num - 1 - i];
        v[num - 1 - i] = aux;
    }
}
int pide_entero(int inf, string mensaje)
{
    do
    {
        cout << "Introduzca el " << mensaje << ": ";
        cin >> valor;
        if (valor > sup)
            cout << "\n\nERROR: el " << mensaje << " no puede sobrepasar " << sup << "\n\n";
        else if (valor < inf)
            cout << "\n\nERROR: el " << mensaje << " debe ser al menos " << inf << "\n\n";
    } while (valor > sup || valor < inf);
    return valor;
}
void carga_vector(int v, int tam)
{
    for (int i = 0; i < tam; ++i)
    {
        cout << "v[" << i << "]= ";
        cin >> v[i];
    }
}
void muestra_vector(int v, int tam)
{
    for (int i = 0; i < tam; ++i)
        cout << v[i] << " ";
    cout << endl;
}
int main()
{
    const int tam_max = 20;
    int v[tam_max];
    int tam = pide_entero(1, tam_max, "numero de elementos del vector");
    carga_vector(v, tam);
    invertir_orden_vector(v, tam);
    muestra_vector(v, tam);
}