//#######################HEADERS
#include <iostream> //Libraries
//#######################HEADERS

using namespace std; //library te ahorras escribir std en cada linea que ocupes 

////#######################MAIN FUNCTION
#pragma region Main //regiones para documentacion
int  main() //funcion principal
{
    ////#######################DEFINIR VARIABLES
   float calif= 0;//declararla provoca una reserva de espacio en la memoria
    char libreta; // variable libreta O.o

    ////#######################DEFINIR VARIABLES


    ////####################### PEDIR VALORES
        cout << "Escriba Calificacion del alumno (0-10) \n" ; //Pide calif al usuario
        cin >> calif; // Recibe calif escrita por usuario
         cout << "Usted ingreso: " << calif << endl; //Comprueba que calif se almaceno correctamente
        cout << "Entrego libreta? (y/n) (y para si, cualquier otro valor será no) \n " ; //Pide entrego libreta al usuario
        cin >> libreta; ////recibe entrego libreta
        cout << "El alumno entrego libreta :) \n"; // comprueba que entrego libreta

     ////####################### PEDIR VALORES

     ////#######################CONDICIONAL

        if (libreta=='y') //inicio de condicional, comprueba si libreta es igual a y
        {   
            calif+=1; // suma 1 a calificacion si la condicion se cumple
        }
    
    ////####################### CONDICIONAL

////####################### RESULTADOS
        cout << "Su calificación es: " << calif << endl; //imprime resultados de calif
////####################### RESULTADOS

      if (calif<7.5) //conficional para saber si el alumno reprobo si su calif es menor a 7.5
      {
        cout << "Reprobado \n";//imprime comentario de que reprobo si se cumplio la condicion
      }else{// sino 
        cout << "Aprobado \n";// imprime comentario de que aprobo :D
      }

#pragma endregion //fin de la region
      
        


////#######################MAIN FUNCTION
}