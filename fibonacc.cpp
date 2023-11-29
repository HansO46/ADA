#include <iostream>

using namespace std;
int fibonancci(int n){
   if (n==0)
   {
     return 0;
   }else if (n==1)
   {
    return 1;
   }
   else
   {
    return(fibonancci(n-1)+ fibonancci(n-2));
   }


}
int main(int argc, char const *argv[])
{
     int numTerminos;

    cout << "Ingrese el número en terminosVde la serie de Fibonancci ";
    cin >> numTerminos;

    if (numTerminos < 0)
    {
        cerr << "El numero de terminos no puede ser negativo" << endl;
        return 1;
    }

    cout << "Serie de Fibonancci con " << numTerminos<< " terminos: " << endl;
    for ( int i =0; i < numTerminos; i++){
        cout << fibonancci(i) << " ";
    }
    cout << endl;

    
    return 0;
}


