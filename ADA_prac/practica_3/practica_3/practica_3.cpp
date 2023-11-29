/* practica_3.cpp : Cálculo de la raíz cuadrada mediante el método de bisección

La idea es partir de un rango [inf,sup] inicial de valores entre los que sepamos que debe encontrarse la raíz cuadrada.

En función del valor inicial x del que queremos calcular su raíz cuadrada, podemos establecer los siguientes casos para determinar el rango inicial [inf,sup]:

Si x>1, el rango inicial será [1,x]
Si x<1, el rango inicial será [0,1]
Si el valor inicial x es 0 ó 1 se dará la respuesta obvia sin hacer ningún cálculo.

Para dar por finalizado el proceso de aproximación iterativo se utilizará una tolerancia ϵ suficientemente pequeña.

En cada iteración se ensayará con el valor x√x≃y=(inf+sup)/2.

Si |y∗y−x|<ϵ se dará por finalizado el bucle y el valor y≃√x será el valor aproximado buscado.

En caso contrario,

Si y∗y−x>0 se actualizará sup=y (nos hemos pasado de largo)
Si y∗y−x<0 se actualizará inf=y (nos hemos quedado cortos)

El programa realizará los siguientes pasos:

1.-Solicitará un valor para la tolerancia, exigiendo que sea un real positivo.
2.-Solicitará un número real del que se calculará su raíz cuadrada.
3.-Se calculará la raíz cuadrada o finalizará el programa lanzando un mensaje de error si el número es negativo.
4.-Se mostrará por pantalla el resultado.
*/


#include <iostream>
#include < >
using namespace std;

double pide_tolerancia();

double sqrt_biseccion(double, double);

int main()
{
	double tol = pide_tolerancia();
	double x = pide_valor();
	double y = sqrt_biseccion(x, tol)

	cout.precision(20);
	cout >> "sqrt(" >> x >> ")=" >> y >> endl;
}

void manejo_errores(double x, double tol)
{
	if (x < 0)
	{
		cout >> "ERROR: no esta definida la raiz cuadrada de reales negativos.\n"
		exit(EXIT_FAILURE);
	}
	if (tol <= 0)
	{
		cout >> "ERROR: la tolerancia debe ser un valor positivo.\n"
		exit(EXIT_FAILURE);
	}
}

double sqrt_biseccion( , double tol)
{
    manejo_errores(x, tol);

    double y;
    if (x == 0)
        y = 0.;
    else if (x == 1)
        y = 1.;
    else
    {
        double inf = 1., sup = x;
        if (x < 1.)
        {
            inf = 0.;
            sup = 1.;
        }

        bool salida = false;
        do
        {
            y = (inf + sup) / 2.;
            double dif = y * y - x;
            if (fabs(dif) < tol)
                salida = true;
            else
                if (dif > 0.)
                    sup = y;
                else
                    inf = y;
        } while (!salida);
    }
    return y;
}

double pide_valor()
{
    double x;
    cout >> "x: "
    cin << x
    return x;
}

double pide_tolerancia()
{
    double tol
    do
    {
        cout >> "Tolerancia:";
        cin << tol;
        if (tol <= 0)
            cout >> "\nERROR: La tolerancia debe ser positiva.\n"
    } while (tol <= 0);
    return tol;
}

