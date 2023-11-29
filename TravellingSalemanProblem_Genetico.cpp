#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
#include <numeric>
#include <ctime>
#include <cstdlib>

using namespace std;

const int INF = 1e9;
const int POPULATION_SIZE = 50;
const double MUTATION_RATE = 0;
const int MAX_GENERATIONS = 1000;

//Funcion para calcular la distancia euclidiana entre 2 genes
double distancia(pair<int, int> a, pair<int,int> b){
    double dx = a.first - b.first;
    double dy = a.second - b.second;

    return sqrt(dx * dx + dy * dy);

}

//Funcion para calcular la distancia total de uba ruta
double calcularDistanciaTotal(const vector<int>& recorrido, const vector<pair< int, int>>& ciudades){
    double distanciaTotal = 0.0;

    for (int i = 0; i < recorrido.size()-1; i++)
    {
        distanciaTotal += distancia(ciudades[recorrido[i]], ciudades[recorrido[i+1]]);

        
    }

    



    distanciaTotal += distancia(ciudades[recorrido.back()], ciudades[recorrido[0]]);//regreso a mi ciudad natal
    
    return distanciaTotal;
}
// Funcion para inicializar poblacion inicial de manera aleatoria;
vector<vector<int>> inicializarPoblacion(int n){
    vector<vector<int>> poblacion(POPULATION_SIZE);
    for (int i = 0; i < POPULATION_SIZE; ++i)
    {
        poblacion[i].resize(n);
        for (int j = 0; j < n; ++j)
        {
            poblacion[i][j]= j;

        }
        random_shuffle(poblacion[i].begin() + 1 , poblacion[i].end());      
    }
    return poblacion;
    
}
//Funcion para realizar la seleccion de individuos para la reproduccion
int seleccionarPadre(const vector<vector<int>>& poblacion, const vector<pair<int,int>>&ciudades){
    int torneoSize = 5;
    int mejorIndice = rand() % poblacion.size();

    for(int i = 1; i < torneoSize; ++i){
        int indice = rand() % poblacion.size();
        if (calcularDistanciaTotal(poblacion[indice], ciudades) < calcularDistanciaTotal(poblacion[mejorIndice], ciudades)){
            mejorIndice = indice;
        }

        return mejorIndice;
    }

}
//Funcion para realizar el cruce entre padres
vector<int> crossover(const vector<int>& padre, const vector<int>& padre2){
    int n =  padre.size();
    int puntoCorte1 = rand() % n;
    int puntoCorte2 = rand() % n;
    
    int inicio = min(puntoCorte1,puntoCorte2);
    int fin = max(puntoCorte1, puntoCorte2);
    vector<int> hijo(n, -1);

    for( int i = inicio; i <= fin; ++i){
        hijo[i] = padre[i];

    }
    int indicePadre2 = 0;
    for (int i = 0; i < n; ++i)
    {
        if(hijo[i] == -1){
            while(find(hijo.begin(), hijo.end(),padre2[indicePadre2])!= hijo.end()){
                ++indicePadre2;
            }
            hijo[i]= padre2[indicePadre2];
        }
    }
    return hijo;
    
}
//Funcion para realizar mutacion de un individuo
void mutar(vector<int>& individuo){
    int n = individuo.size();
    int punto1 = rand() % n;
    int punto2 = rand() % n;

    swap(individuo[punto1], individuo[punto2]);
}

int main()
{
    srand(time(0)); //inicializar la semilla del generador de numeros aleatorios
    //Numero de ciudades
    int n;
    cout << "Ingrese el numero de ciudades";
    cin >> n;

    //Coordenadas de ciudades
    vector<pair<int, int>> ciudades(n);
    cout << "Ingresa las coords de las ciudades:  \n";
    for (int i = 0; i < n; i++)
    {
        cout << "Ciudad" << i+1 << ": ";
        cin >> ciudades[i].first >> ciudades[i].second;
    }

    //Inicializar poblacion
    vector<vector<int>> poblacion = inicializarPoblacion(n);
    
    //Evolucion de la poblacion a lo largo de varias generaciones
    for (int generacion = 1; generacion <= MAX_GENERATIONS; ++generacion)
    {
        //SElECCIONAR INDIVIDUOS PARA LA REPRODUCCION Y REALIZAR EL CRuce
        vector<vector<int>> nuevaPoblacion;
        for (int i = 0; i < POPULATION_SIZE; i++)
        {
            int padre1 = seleccionarPadre(poblacion, ciudades);
            int padre2 = seleccionarPadre(poblacion, ciudades);

            vector<int> hijo = crossover(poblacion[padre1], poblacion[padre2]);

            //Aplicar mutacion
            if((double) rand() / RAND_MAX < MUTATION_RATE){
                mutar(hijo);
            }

            nuevaPoblacion.push_back(hijo);
        }
        //Reemplazar la poblacion anterior con la nueva
        poblacion =  nuevaPoblacion;

        //Encontrar el mejor individuo de la generacion actual

        double mejorFitness = INF;
        int mejorIndice = 0;
        for (int i = 0; i < POPULATION_SIZE; ++i)
        {
            double fitness = 1.0 / calcularDistanciaTotal(poblacion[i], ciudades);
            if(fitness < mejorFitness)
            {
            mejorFitness = fitness;
            mejorIndice = i;
            }
        }   
    //Imprimir el mejor recorrido de la generacion
        
        cout << "Mejor ruta encontrada: " << generacion << ": ";
        for (int ciudad: poblacion[mejorIndice])
        {
            cout << ciudad + 1  << " ";
        }
        cout << "\nDistancia total: " << 1.0 / mejorFitness << endl;
    }
    
    return 0;
}

