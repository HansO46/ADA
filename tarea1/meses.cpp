/*
meses.cpp: Devuelve el numero de disa que tiene el mes indicando dicho mes
    If's anidados
*/
#include <iostream>// bibliotecas
#include <chrono>

using namespace std; //espacios de nombre

   ////////////////////////////////////////////////////
    /*       NOTACION BIG_O = O(1)     
               Tiempo de procesamiento: 2467 milisegundos
                   */
    ////////////////////////////////////////////////////



int main() //funcion principal
{
    int mes;//declarar variables
    cout << "Inserta el numero de mes ";//pedir variable al user
    auto start_time = std::chrono::high_resolution_clock::now();
    cin >> mes;// guardar variable

    if (mes > 0 && mes < 13)//condicion para ajustar mes a un intervalo 1-12
    {
        if (mes == 1 )//comprueba los meses de 31 dias
        {
             cout << "31 dias"; //imprime el numero de dias
        }else if (mes == 2 )//comprueba los meses de 31 dias
        {
             cout << "28 o 29 dias";//imprime el numero de dias
        }else if (mes == 3 )//comprueba los meses de 31 dias
        {
             cout << "31 dias";//imprime el numero de dias

        }else if (mes == 4 )//comprueba los meses de 31 dias
        {
             cout << "30 dias";//imprime el numero de dias
        }else if (mes == 5 )//comprueba los meses de 31 dias
        {
             cout << "31 dias";//imprime el numero de dias

        }else if (mes == 6 )//comprueba los meses de 31 dias
        {
             cout << "30 dias";//imprime el numero de dias
        }else if (mes == 7 )//comprueba los meses de 31 dias
        {
             cout << "31 dias";//imprime el numero de dias

        }else if (mes == 8)//comprueba los meses de 31 dias
        {
             cout << "31 dias";//imprime el numero de dias

        }else if (mes == 9 )//comprueba los meses de 31 dias
        {
             cout << "30 dias";//imprime el numero de dias
        }else if (mes == 10 )//comprueba los meses de 31 dias
        {
             cout << "31 dias";//imprime el numero de dias

        }else if (mes == 11)//comprueba los meses de 31 dias
        {
             cout << "30 dias";//imprime el numero de dias
        }
        else if (mes == 12)//comprueba los meses de 31 dias
        {
             cout << "31 dias";//
        }

        
        
    }else
    {
        cout << "ese mes no existe bro";// imprime que no existe el messillo
    }
    
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    cout << "Tiempo de procesamiento: " << duration.count() << " milisegundos" << std::endl;


}