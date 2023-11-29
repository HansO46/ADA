 ////////////////////////////////////////////////////
    /*       NOTACION BIG_O = O(1)              

    
El mes tiene 30 diasTiempo de procesamiento: 1694 milisegundos          */
    ////////////////////////////////////////////////////

#include <iostream>//bilbiotecas
#include <chrono>


using namespace std;// espacio de nombres

int main()//main
{
    int mes;//declarar var
    cout << "Inserta el numero de mes ";//pedir data a user
    auto start_time = std::chrono::high_resolution_clock::now();
    cin >> mes;// guardar data en mes

   while (mes < 1 || mes >12)// comprobar que mes sea 12
   {
    cout << "Intenta de nuevo. Inserta el numero de mes \n";//en caso contrario se "atora en el bucle"
    cin >> mes;//guarda el nuevo valor
   }
   
        if (mes == 1 || mes ==3 || mes == 5 || mes == 7 || mes== 8 || mes== 10 || mes == 12)//comprueba el mes
        {
            cout << "El mes tiene 31 dias";//regresa el no° de dias 
        }else if (mes == 2 )//comprueba el mes
        {
            cout << "El mes tiene 28 o 29 dias";//regresa el no° de dias 
        }else{
            cout << "El mes tiene 30 dias";//regresa el no° de dias 
            
        }

       ////////////////////////////////////////////////////
    /*       NOTACION BIG_O = O(1)                    */
    ////////////////////////////////////////////////////
    
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    cout << "Tiempo de procesamiento: " << duration.count() << " milisegundos" << std::endl;




}