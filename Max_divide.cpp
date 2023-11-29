
//
#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>

using namespace std;
using namespace chrono;
unsigned t0 , t1;

int encontrarMaximoDV(const vector<int> & arreglo_random, int inicio, int fin){
    if(arreglo_random.empty()){
        cerr << "El arreglo_random esta vacio." << endl; // MENSAJE DE ERROR EN ROJO
        return -1;//valor de retorno que indica un error
    }
    
    //caso base sisolo hay un elemento en el subarreglo
    if(inicio == fin){
        return arreglo_random[inicio];

    }
    
    //encontrar la mitad del  subarreglo
    int mitad= (inicio+ fin)/2;
    //cout << mitad << endl;
    //encontrar el maximo en la mitad izquierda y en la mitad derecha
    int maxIzquierda = encontrarMaximoDV(arreglo_random,inicio,mitad);
    int maxDerecha = encontrarMaximoDV(arreglo_random,mitad+1, fin);

    //Combinar resultados de cada mitad
    return max(maxIzquierda, maxDerecha);

    
}

int main()
{
    int valores;
    cout << "Ingresa la longuitud del arreglo_random: ";
    cin >> valores;
    t0= clock();
    auto start = high_resolution_clock::now();

    vector<int> arreglo_random = {};
    arreglo_random.resize(valores);
    srand(time(0));
    int aux = 0;

    for (int i = 0; i < valores; i++)
    {
        aux = (1 + rand() % 2000);
        int aux2 = 0;
        while (aux2 < i)
        {
            if(aux != arreglo_random[aux2]){
                aux2++;
            }else{
                aux = (1+ rand() % 2000);
                aux2= 0;
            }
        }
        
        arreglo_random[i]= aux;
        cout << arreglo_random[i]<< "\n";
    }
    
 
    int maximo = encontrarMaximoDV(arreglo_random, 0 , arreglo_random.size() -1);

    if(maximo != -1)
    {

        cout << "El maximo en el arreglo_random es: " << maximo << endl;

    }
    t1= clock();
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(end-start);
    cout << "duration: "<< duration.count()<< " sec"<< endl;
    double time = (double(t1-t0))/CLOCKS_PER_SEC;
    cout << "time: " << time;
    return 0;
}

