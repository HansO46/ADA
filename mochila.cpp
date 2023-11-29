#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct Elemento

{
    int peso;
    int valor;
};
//Funcion para resolver el problema de la mochila

int mochila (vector<Elemento>& elementos, int capacidad){
    int n = elementos.size();

    vector<vector<int>> dp(n + 1, vector<int>(capacidad +1 , 0));

    for (int i = 1; i <= n; ++i)
    {
        for (int w = 0; w <= capacidad; ++w)
        {
            if(elementos[i-1].peso <= w)
            {
                dp[i][w] = max(dp[i-1][w], elementos[i-1].valor + dp[i-1][w-elementos[i-1].peso]);
            }
            else
            {
                dp[i][w]=dp[i-1][w];

            }
            
        }
        
    }
    
    return dp[n][capacidad];
}


int main()
{
    //Definir elementos (peso, valor)
    vector<Elemento> elementos = {{2,10},{3,7},{4,15},{5,5}};

    //Capacidad de mochila
    int capacidad = 8;

    //Resolver el problema de la mochila
    int resultado = mochila(elementos, capacidad);

    //Mostrar resultado
    cout << "El valor maximo que se puede obtener es: " << resultado;

    return 0;
}