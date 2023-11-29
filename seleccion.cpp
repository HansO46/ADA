#include<iostream>

void seleccion(int longitud,int* array);
void imprimir(int longitud,int* array);

int main()
{
    int longi;
    std::cin>> longi;
    int* array = new int [longi];
    for (int i = 0; i < longi; i++)
    {
        std::cin>>array[i];
    }
    
    
    seleccion(longi, array);
   
    delete[] array;
    return 0;
}

void seleccion(int longitud, int* array){
    int menor;
    int aux;
    for (int i = 0; i < longitud - 1; i++) 
    {
        menor = i;
        for (int j = i + 1; j < longitud; j++)
        {
            if (array[j] < array[menor])
            {
                menor = j;
            }
        }
        aux = array[i];
        array[i] = array[menor];
        array[menor] = aux;
        
        std::cout<<std::endl;
        imprimir(longitud, array);
    }
}

void imprimir(int longitud,int* array){
    for (int k = 0; k < longitud; k++)
        {
            std::cout<< array[k]<<" ";
        }
}