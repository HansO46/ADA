/*
meses.cpp: Devuelve el numero de disa que tiene el mes indicando dicho mes
    If's anidados

    tiempo
    comentar todo el codigo 
    y hacer notacion big_O
*/
   ////////////////////////////////////////////////////
    /*       NOTACION BIG_O = O(1)              
    El mes tiene 30 diasTiempo de procesamiento: 1205 milisegundos
          */
    ////////////////////////////////////////////////////

#include <iostream>//bibliotecas
#include <chrono>


using namespace std;//espacio de nombres

int main()//main function
{
    int mes;// declaracion variable
    cout << "Inserta el numero de mes ";//pedir data al user
    auto start_time = std::chrono::high_resolution_clock::now();
    cin >> mes;// guardar data en variable

    if (mes > 0 && mes < 13)//condicion de mes en intervalo 1-12
    {
        switch (mes)//switch case para los meses 12
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            cout << "El mes tiene 31 dias"; // imprime dias de mes     
            break;//rompe el switch
        case 6:
        case 9:
        case 11:
            cout <<  "El mes tiene 30 dias";// imprime dias de mes
            break;
        case 2:
            cout << "El mes tiene 28 o 29 dias";      // imprime dias de mes
            break;              
        default:
            cout << "Imposible";// imprime CASO imposible
            break;
        }
   
    }else
    {
            
        cout << "ese mes no existe bro";//imprime que hubo un error
    }
    
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    cout << "Tiempo de procesamiento: " << duration.count() << " milisegundos" << std::endl;

    


}