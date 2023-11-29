
/* BIBLIOTECAS */
#include <iostream>
#include <curses.h> //linux
//#include<conio.h> windows
#include<string.h>
#include <ctime>
/* BIBLIOTECAS */

/* DEFINIR UNA CONSTANTE*/
#define MAX 500000000 // MAYUSCULAS POR CONVENCION
/* DEFINIR UNA CONSTANTE*/

/*  ARRAY DE VARIABLES ??????????*/
struct ordenamiento
{
	int elem;
    int prueba;
};
/*  ARRAY DE VARIABLES ??????????*/

unsigned t0,t1;


/* DECLARACION DE FUNCIONES*/
void leerarray(int, struct ordenamiento[]); //void -> Vacio
void burbuja(int, struct ordenamiento[]);
void muestra(int, struct ordenamiento[]);
/* ES NECESARIO DECLARAR FUNCIONES*/
/* ES NECESARIO DECLARAR FUNCIONES*/
/*
        PROGRAMACION ESTRUCTURADA
*/
/* ES NECESARIO DECLARAR FUNCIONES*/
/* ES NECESARIO DECLARAR FUNCIONES*/
/* DECLARACION DE FUNCIONES*/

/*  MANEJO DE NOMBRES DE ESPACIOS*/
using namespace std;
/*  MANEJO DE NOMBRES DE ESPACIOS*/

int main()
{
    t0 = clock();
	int n;//tamaño del arreglo en entero
	struct ordenamiento orden[MAX];//reserva de memoria
	cout << "Ingrese limite del arreglo:";
	cin >> n;//+1
	leerarray(n, orden);
	burbuja(n, orden);
	cout << endl << "El arreglo ordenado es:" << endl;
	muestra(n, orden);
    t1= clock();

    double time = (double(t1-t0)*1000/ CLOCKS_PER_SEC);
    cout << "Execution time: " << time << "s" << endl;
	getchar();
    return 0;
}
void leerarray(int n, struct ordenamiento a[])
{
	for (int i = 0; i < n; i++) //3n
	{
		cout << "Ingrese elemento " << i << ":";

		cin >> a[i].elem; //guarda en a[0] ".elem  +2
        a[i].prueba=a[i].elem;// +3
        cout << a[i].prueba;//+4
	}
}
void burbuja(int n, struct ordenamiento a[])
{
	int i, j;
	struct ordenamiento temp; //4n^2
	for (i = 1; i < n; i++)
		for (j = n - 1; j >= i; j--)/* NO LLEVAN LLAVES WAO*/
			
			if (a[j - 1].elem > a[j].elem)
			{
				temp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = temp;
			}
}
void muestra(int n, struct ordenamiento a[])
{
	for (int i = 0; i < n; i++)//n
		cout << " " << a[i].elem;
}