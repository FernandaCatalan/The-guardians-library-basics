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
using std::cout;
using std::endl;

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

// Heap Sort
void heapSort(vector<int>& datos, bool orden)
{
    int tamano = datos.size();
    for (int i = tamano / 2 - 1; i >= 0; --i)
    {
        heapify(datos, tamano, i, orden);
    }

    for (int i = tamano - 1; i >= 0; --i)
    {
        swap(datos[0], datos[i]);
        heapify(datos, i, 0, orden);
    }
}

void quickSort(vector<int>& datos, int inicio, int fin, bool orden)
{
    stack<pair<int, int>> pila;
    pila.push(make_pair(inicio, fin));

    while (!pila.empty())
    {
        int inicioActual = pila.top().first;
        int finActual = pila.top().second;
        pila.pop();

        if (inicioActual >= finActual)
            continue;

        int pivote = datos[finActual];
        int i = inicioActual - 1;

        for (int j = inicioActual; j <= finActual - 1; ++j)
        {
            if (orden)
            {
                if (datos[j] < pivote)
                {
                    ++i;
                    swap(datos[i], datos[j]);
                }
            }
            else
            {
                if (datos[j] > pivote)
                {
                    ++i;
                    swap(datos[i], datos[j]);
                }
            }
        }

        swap(datos[i + 1], datos[finActual]);
        int indicePivote = i + 1;

        pila.push(make_pair(inicioActual, indicePivote - 1));
        pila.push(make_pair(indicePivote + 1, finActual));
    }
}


void merge(vector<int>& datos, int inicio, int medio, int fin, bool orden)
{
    int tamanoIzquierda = medio - inicio + 1;
    int tamanoDerecha = fin - medio;

    vector<int> izquierda(datos.begin() + inicio, datos.begin() + medio + 1);
    vector<int> derecha(datos.begin() + medio + 1, datos.begin() + fin + 1);

    int indiceIzquierda = 0;
    int indiceDerecha = 0;
    int indiceMerge = inicio;

    while (indiceIzquierda < tamanoIzquierda && indiceDerecha < tamanoDerecha)
    {
        if (orden)
        {
            if (izquierda[indiceIzquierda] <= derecha[indiceDerecha])
            {
                datos[indiceMerge] = izquierda[indiceIzquierda];
                ++indiceIzquierda;
            }
            else
            {
                datos[indiceMerge] = derecha[indiceDerecha];
                ++indiceDerecha;
            }
        }
        else
        {
            if (izquierda[indiceIzquierda] >= derecha[indiceDerecha])
            {
                datos[indiceMerge] = izquierda[indiceIzquierda];
                ++indiceIzquierda;
            }
            else
            {
                datos[indiceMerge] = derecha[indiceDerecha];
                ++indiceDerecha;
            }
        }
        ++indiceMerge;
    }

    while (indiceIzquierda < tamanoIzquierda)
    {
        datos[indiceMerge] = izquierda[indiceIzquierda];
        ++indiceIzquierda;
        ++indiceMerge;
    }

    while (indiceDerecha < tamanoDerecha)
    {
        datos[indiceMerge] = derecha[indiceDerecha];
        ++indiceDerecha;
        ++indiceMerge;
    }
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

// Selection Sort
void selectionSort(vector<int>& datos, bool orden)
{
    int tamano = datos.size();

    for (int i = 0; i < tamano - 1; ++i)
    {
        int indiceExtremo = i;
        for (int j = i + 1; j < tamano; ++j)
        {
            if (orden)
            {
                if (datos[j] < datos[indiceExtremo])
                {
                    indiceExtremo = j;
                }
            }
            else
            {
                if (datos[j] > datos[indiceExtremo])
                {
                    indiceExtremo = j;
                }
            }
        }
        swap(datos[i], datos[indiceExtremo]);
    }
}

// Merge Sort
void mergeSort(vector<int>& datos, int inicio, int fin, bool orden)
{
    if (inicio < fin)
    {
        int medio = inicio + (fin - inicio) / 2;
        mergeSort(datos, inicio, medio, orden);
        mergeSort(datos, medio + 1, fin, orden);
        merge(datos, inicio, medio, fin, orden);
    }
}

// Función para realizar la carrera
void carrera(int set, vector<int>& datos, bool orden) 
{
    switch (set)
    {
    case 1:
        cout << " Modo Aleatorio sin repetir" << endl;
        break;
    case 2:
        cout << " Modo Aleatorio con repetir" << endl;
        break;
    case 3:
        cout << " Modo Ordenado" << endl;
        break;
    case 4:
        cout << " Modo Inversamente Ordenado" << endl;
        break;
    default:
        break;
    }

    // Variables para el algoritmo más rápido
    int algoritmoMasRapido = -1;
    double tiempoMasRapido = std::numeric_limits<double>::max();

    // BubbleSort
    vector<int> a1 = datos;
    auto inicio = std::chrono::high_resolution_clock::now();
    bubbleSort(a1, orden);
    auto fin = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duracion = fin - inicio;
    cout << "1. Bubble Sort, " << duracion.count() << " segundos" << endl;

    // Actualizar el algoritmo más rápido
    if (duracion.count() < tiempoMasRapido)
    {
        algoritmoMasRapido = 1;
        tiempoMasRapido = duracion.count();
    }


    // Merge Sort
    vector<int> a4 = datos;
    inicio = std::chrono::high_resolution_clock::now();
    mergeSort(a4, 0, a4.size() - 1, orden);
    fin = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duracion4 = fin - inicio;
    cout << "4. Merge Sort, " << duracion4.count() << " segundos" << endl;

    // Actualizar el algoritmo más rápido
    if (duracion4.count() < tiempoMasRapido)
    {
        algoritmoMasRapido = 4;
        tiempoMasRapido = duracion4.count();
    }

    // Selection Sort
    vector<int> a5 = datos;
    inicio = std::chrono::high_resolution_clock::now();
    selectionSort(a5, orden);
    fin = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duracion5 = fin - inicio;
    cout << "5. Selection Sort, " << duracion5.count() << " segundos" << endl;

    // Actualizar el algoritmo más rápido
    if (duracion5.count() < tiempoMasRapido)
    {
        algoritmoMasRapido = 5;
        tiempoMasRapido = duracion5.count();
    }

    // HeapSort
    vector<int> a2 = datos;
    inicio = std::chrono::high_resolution_clock::now();
    heapSort(a2, orden);
    fin = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duracion2 = fin - inicio;
    cout << "2. Heap Sort, " << duracion2.count() << " segundos" << endl;

    // Actualizar el algoritmo más rápido
    if (duracion2.count() < tiempoMasRapido)
    {
        algoritmoMasRapido = 2;
        tiempoMasRapido = duracion2.count();
    }

}

int main(){



    return 0;
}