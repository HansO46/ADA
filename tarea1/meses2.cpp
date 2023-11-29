/*
meses.cpp: Devuelve el numero de disa que tiene el mes indicando dicho mes
    If's anidados
*/
   ////////////////////////////////////////////////////
    /*       NOTACION BIG_O = O(1)     
        Tiempo de procesamiento: 1183 milisegundos
                   */
    ////////////////////////////////////////////////////
#include <iostream>// bibliotecas
#include <chrono>



using namespace std; //espacios de nombre

int main() //funcion principal
{
    int mes;//declarar variables
    cout << "Inserta el numero de mes ";//pedir variable al user
    auto start_time = std::chrono::high_resolution_clock::now();
    cin >> mes;// guardar variable

    if (mes > 0 && mes < 13)//condicion para ajustar mes a un intervalo 1-12
    {
        if (mes == 1 || mes ==3 || mes == 5 || mes == 7 || mes== 8 || mes== 10 || mes == 12)//comprueba los meses de 31 dias
        {
            cout << "El mes tiene 31 dias";// imprime los dias que corresponden a los meses
        }else if (mes == 2 )// if anidado donde comprueba si es febrero
        {
            cout << "El mes tiene 28 o 29 dias";// imprime los dias que corresponden a los meses
        }else{
            cout << "El mes tiene 30 dias";// imprime los dias que corresponden a los meses
            
        }
        
        
    }else
    {
        cout << "ese mes no existe bro";// imprime que no existe el mes
    }
    
       ////////////////////////////////////////////////////
    /*       NOTACION BIG_O = O(1)                    */
    ////////////////////////////////////////////////////
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    cout << "Tiempo de procesamiento: " << duration.count() << " milisegundos" << std::endl;


}