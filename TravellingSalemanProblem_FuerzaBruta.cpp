//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
#include <numeric>

using namespace std;

const double INF = numeric_limits<double>::max();


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

int main()
{
    vector<Ciudad> cuidades ={ //vector conformado por tuplas
        Ciudad(0,0),
        Ciudad(1,2),
        Ciudad(2,4),
        Ciudad(3,1),
        Ciudad(4,3)

    };

    int numCiudades = cuidades.size();
    vector<int> rutaActual(numCiudades);

    //Inicializa la ruta actual con una permutacion inicial
    iota(rutaActual.begin(), rutaActual.end(),0);

    double mejorDistancia = INF;
    vector<int> mejorRuta;

    do
    {
        double distanciaActual =  calcularDistanciaTotal(cuidades,rutaActual);
        if (distanciaActual < mejorDistancia)
        {
            mejorDistancia = distanciaActual;
            mejorRuta = rutaActual;
        }
        
    } while (next_permutation(rutaActual.begin()+ 1 , rutaActual.end()));


    cout << "Mejor ruta encontrada: ";
    for (int ciudad: mejorRuta)
    {
        cout << ciudad << " ";
    }
    cout << "\nDistancia total: " << mejorDistancia << endl;
    
    return 0;
}
