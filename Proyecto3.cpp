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