//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
#include <numeric>
#include <ctime>
#include <cstdlib>



using namespace std;

//const double INF = numeric_limits<double>::max();


// Estructura para representar una ciudad
struct Ciudad{
    double x,y;

    Ciudad(double x, double y): x(x), y(y) {}
};

//Funcion para calcular la distancia euclidiana entre 2 cuidades
double distancia(const Ciudad& ciudad1, const Ciudad& ciudad2){
    double dx = ciudad1.x - ciudad2.x;
    double dy = ciudad1.y - ciudad2.y;

    return sqrt(dx * dx + dy * dy);

}


//Funcion para calcular la distancia total de uba ruta
double calcularDistanciaTotal(const vector<Ciudad>& ciudades, const vector<int>& ruta){
    double distanciaTotal = 0.0;
    int numCiudades = ciudades.size();
    for (int i = 0; i < numCiudades-1; i++)
    {
        distanciaTotal += distancia(ciudades[ruta[i]], ciudades[ruta[i+1]]);

        
    }

    



    distanciaTotal += distancia(ciudades[ruta[numCiudades-1]], ciudades[ruta[0]]);//regreso a mi ciudad natal
    
    return distanciaTotal;
}

//FUNCION DE RECOSIDO SIMULADO PARA RESOLVER EL TSP

vector<int> recosidoSimulado(const vector<Ciudad>& ciudades, double temperaturaInicial, double factorEnfriamiento, int numIteraciones){

    int numCiudades = ciudades.size();
    vector<int> rutaActual(numCiudades);

    for (int i = 0; i < numCiudades; i++)
    {
        rutaActual[i] = i;

    }

    random_shuffle(rutaActual.begin(),rutaActual.end());

    double distanciaActual = calcularDistanciaTotal(ciudades, rutaActual);
    double temperatura = temperaturaInicial;

    for (int i = 0; i < numIteraciones; i++)
    {
        int ciudad1 = rand() % numCiudades;
        int ciudad2 = rand() % numCiudades;
        
        swap(rutaActual[ciudad1], rutaActual[ciudad2]);

        double nuevaDistancia = calcularDistanciaTotal(ciudades, rutaActual);
        double diferenciaDistancia = nuevaDistancia - distanciaActual;

        if(diferenciaDistancia < 0 || (rand()/ double(RAND_MAX)) < exp(-diferenciaDistancia/ temperatura))
        {
            distanciaActual = nuevaDistancia;
        }
        else
        {
            swap(rutaActual[ciudad1], rutaActual[ciudad2]);

        }

        temperatura *= factorEnfriamiento;


    }

    return rutaActual;    

}

    # define RAND_MAX = 100;

int main()
{
    int num = 0;
    cout << "Numero de cuidades: ";
    cin >> num;
    if (num == 0){
        return -1;
    }
    vector<Ciudad> cuidades;
    
    for (int i = 0; i < num; i++)
    {
        int x = rand() % (100 + 1 - 0) + 0;
        int y = rand() % (100 + 1 - 0) + 0;
         cuidades.push_back(Ciudad(x, y));
        cout << "Ciudad " << i+1<< " Coordenadas: ("<< x<< ","<<y<<")"<< endl;
    }
    


    double temperaturaInicial = 1000.0;
    double factorEnfriamiento = 0.99;
    int numIteraciones = 20000;
    
    vector<int> mejorRuta = recosidoSimulado(cuidades,temperaturaInicial,factorEnfriamiento,numIteraciones);

    
    cout << "Mejor ruta encontrada: ";
    for (int ciudad: mejorRuta)
    {
        cout << ciudad << " ";
    }
    cout << "\nDistancia total: " << calcularDistanciaTotal(cuidades,mejorRuta) << endl;
    
    return 0;
}
