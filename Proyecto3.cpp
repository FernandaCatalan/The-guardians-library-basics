#include <iostream>
#include <string>
#include <random>
#include <set>
#include <algorithm>
#include <iterator>
#include <chrono>
#include <stack>
#include <utility>
#include <vector>
#include <numeric>

using namespace std;

// Imprimir algoritmo mas rapido
void impMasRapido(int algMasRapido, double tempMasRapido)
{
    cout << "El ganador es: ";

    switch (algMasRapido)
    {
    case 1:
        cout << "Bubble Sort";
        break;
    case 2:
        cout << "Heap Sort";
        break;
    case 3:
        cout << "Quick Sort";
        break;
    case 4:
        cout << "Merge Sort";
        break;
    case 5:
        cout << "Selection Sort";
        break;
    case 6:
        cout << "Insertion Sort";
        break;
    case 7:
        cout << "Shell Sort";
        break;
    default:
        break;
    }

    cout << " con un tiempo de " << tempMasRapido << " segundos" << endl;
}

// Bubble Sort
void bubbleSort(vector<int>& datos, bool orden)
{
    int tamano = datos.size();
    for (int i = 0; i < tamano - 1; ++i)
    {
        for (int j = 0; j < tamano - i - 1; ++j)
        {
            if (orden)
            {
                if (datos[j] > datos[j + 1])
                {
                    swap(datos[j], datos[j + 1]);
                }
            }
            else
            {
                if (datos[j] < datos[j + 1])
                {
                    swap(datos[j], datos[j + 1]);
                }
            }
        }
    }
}

void heapify(vector<int>& datos, int tamano, int indice, bool orden)
{
    int mayor = indice;
    int izquierda = 2 * indice + 1;
    int derecha = 2 * indice + 2;

    if (orden)
    {
        if (izquierda < tamano && datos[izquierda] > datos[mayor])
        {
            mayor = izquierda;
        }

        if (derecha < tamano && datos[derecha] > datos[mayor])
        {
            mayor = derecha;
        }
    }
    else
    {
        if (izquierda < tamano && datos[izquierda] < datos[mayor])
        {
            mayor = izquierda;
        }

        if (derecha < tamano && datos[derecha] < datos[mayor])
        {
            mayor = derecha;
        }
    }

    if (mayor != indice)
    {
        swap(datos[indice], datos[mayor]);
        heapify(datos, tamano, mayor, orden);
    }
}

int main(){



    return 0;
}