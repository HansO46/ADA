/* practica_2.cpp : Simulación de la multiplicación entera por hardware

La idea es implementar el programa de multiplicación hardware visto en los ejemplos del tema de Control de flujo iterativo, pero ahora usando funciones. Para ello:

1.-Se solicitará dos operandos enteros al usuario

2.-Se calculará el producto usando el algoritmo de multiplicación hardware

3.-Se mostrará por pantalla el resultado.

4.-Se preguntará al usuario si desea realizar otro cálculo. En caso afirmativo se volverá al punto 1. En caso contrario, finalizará el programa.

*/

#include <iostream>
using namespace std;

void introduce_operandos(int&, int&);
int producto_hardware(int);

int main()
{
    do
    {
        int num1, num2;
        introduce_operandos(num1, num2);
        cout << num1 << '*' << num2 << "=" << producto_hardware(num1, num2) << endl;

        cout << "\nDesea realizar una nueva operacion?\n"
            << "Conteste s o S para continuar.\n"
            << "Respuesta: ";
        cin >> respuesta;
    } while (respuesta == 's' || respuesta == 'S');
}

void introduce_operandos(int& num1)
{
    cout << "Primer operando: ";
    cin >> num1;
    cout << "Segundo operando: ";
    cin >> num2;
}


int producto_hardware(int x, int y)
{
    int signo = 1;

    if (x != 0 && y != 0) // Si alguno es 0 no hacemos nada, producto=0.
    {
        // La variable contador cuenta los cambios de signo realizados. Si solo
        // se realiza un cambio, el producto será negativo.
        int contador = 0;
        if (x < 0)
        {
            x *= -1;
            ++contador;
        }
        if (y < 0)
        {
            y *= -1;
            ++contador;
        }
        if (contador == 1)
            signo = -1;

        while (y)
        {
            if (y % 2)  // Es impar
            {
                producto += x;
                y = y - 1;
            }
            else
            {
                x = x * 2;
                y = y / 2;
            }
        }
    }
    return signo;
}