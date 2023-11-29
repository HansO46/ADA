 ////////////////////////////////////////////////////
    /*       NOTACION BIG_O = O(1)              

    
Tiempo de procesamiento: 1021 milisegundos*/

    ////////////////////////////////////////////////////

#include <iostream>//bibliotecas
#include <chrono>


using namespace std;//espacio para nombres

int main()//funcion main
{
    int mes;//declarando
    auto start_time = std::chrono::high_resolution_clock::now();

   do//hace primero el codigo y despues la condicion
   {
    cout << "Inserta el numero de mes ";//pide data
    cin >> mes;// guarda data en var
   } while (mes<1 || mes >12);// comprueba la condicion una vez hecho el bloque anterior
   
   
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