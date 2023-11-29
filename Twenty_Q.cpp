#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

struct Nodo
{
    string valor;
    Nodo* izquierda;        //apuntadores de memoria
    Nodo* derecha;

};

Nodo* crearNodo(string valor){
    Nodo* nodo = new Nodo();
    nodo -> valor = valor;
    nodo -> izquierda = nullptr;
    nodo ->derecha =nullptr;
    return nodo;
}

void jugar20Q(Nodo* nodo){
    cout << "Piensa en un objeto (animal, planta, etc.) y yo lo intentare adivinar em 20 preguntas o menos  \n";
    cout << "Por favor, responde 'si' o 'no' a mis preguntas \n";

    while (nodo->derecha != nullptr || nodo->izquierda!= nullptr)
    {
        cout << "¿Es " << nodo->valor << " ? ";
        string respuesta;
        cin >> respuesta;

        if (respuesta== "si")
        {
            nodo = nodo-> izquierda;
        }else if (respuesta == "no")
        {
            nodo = nodo ->derecha;
        }
        else
        {
            cout << "respuesta no valida. Por favor, responde 'si' o 'no' \n";
        }
        
    }
    
    cout << "Adivine! ¿Es un(a)" << nodo -> valor << " ? ";
    string respuestaFinal;
    cin >> respuestaFinal;
    if (respuestaFinal == "si" ){
        cout<< "¡Gane! Gracias por jugar ";
    }else if(respuestaFinal == "no")
    {
        cout << "Oh no! Me equivoque. ¿Que objeto tenias en mente? ";
    }
    string nuevoObjeto;
    cin.ignore();
    getline(cin, nuevoObjeto);

    cout << "Por favor, dame una pregunta que pueda distinguir " << nodo->valor << " de " << nuevoObjeto <<".\n";
    string nuevaPregunta;
    cin.ignore();
    getline(cin, nuevaPregunta);

    cout << "Para " << nuevoObjeto << ", ¿cual seria la respuesta? ";
    string respuestaNueva;
    cin >> respuestaNueva;

    Nodo* nuevoNodo = crearNodo("nuevaPregunta");
    Nodo* objetoActual = crearNodo(nodo-> valor);
    if(respuestaNueva == "si")
    {
        nuevoNodo -> izquierda = nuevoNodo->derecha = objetoActual;
    }
    else if (respuestaNueva == "no")
    {
        nuevoNodo->izquierda = objetoActual;
        nuevoNodo->derecha = crearNodo(nuevoObjeto);

    }
    
    nodo-> valor = "";
    nodo->izquierda = nuevoNodo;
    nodo->derecha = nullptr;

    cout << "Gracias por enseñarme. ¿Quieres jugar de nuevo? ";
    string jugarDeNuevo;
    cin>> jugarDeNuevo;

    if (jugarDeNuevo == "si")
    {
        jugar20Q(nodo);
    }
    else
    {
        cout << "Hasta la proxima! \n";
        return;
    }
    



}



int main(int argc, char const *argv[])
{
    Nodo* raiz = crearNodo("un animal");
    raiz -> izquierda = crearNodo("perro");
    raiz -> derecha = crearNodo("gato");

    jugar20Q(raiz);

    return 0;
}
