
//
#include <iostream>
#include <vector>
#include <chrono>


using namespace std;


int encontrarMaximoFB(const vector<int> & arreglo){
    if(arreglo.empty()){
        cerr << "El arreglo esta vacio." << endl; // MENSAJE DE ERROR EN ROJO
        return -1;//valor de retorno que indica un error
    }
    
    int maximo = arreglo[0];

    for (int i = 1; i < arreglo.size(); i++)
    {
        if (arreglo[i]>maximo)
        {
            maximo=arreglo[i];
        }
    }
    
    return maximo;
    
}

int main()
{
    vector<int> arreglo = {3,10,5,8,12,7,2,11};
    int maximo = encontrarMaximoFB(arreglo);
    if(maximo != -1)
    {

        cout << "El maximo en el arreglo es: " << maximo << endl;

    }
    return 0;
}