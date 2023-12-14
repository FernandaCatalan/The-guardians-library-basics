# Proyecto 3: The guardians library-basics

## Descripción del proyecto
Este proyecto consiste en un código en C++ implementa varios algoritmos de ordenamiento y realiza una "carrera" para determinar cuál es el más rápido en diferentes conjuntos de datos. A continuación, se proporciona una descripción detallada de las funcionalidades y estructura del código.

## Link presentacion
https://docs.google.com/presentation/d/1gsz8LMyO1z1_4TKGDppjsTXbBaeBVrhU/edit#slide=id.p1

## Funciones implementadas

### Algoritmos de Ordenamiento
1. Bubble Sort: Implementa el algoritmo de ordenamiento burbuja.
2. Heap Sort: Implementa el algoritmo de ordenamiento por montículos.
3. Quick Sort: Implementa el algoritmo de ordenamiento rápido.
4. Merge Sort: Implementa el algoritmo de ordenamiento por fusión.
5. Selection Sort: Implementa el algoritmo de ordenamiento por selección.
6. Insertion Sort: Implementa el algoritmo de ordenamiento por inserción.
7. Shell Sort: Implementa el algoritmo de ordenamiento por Shell.

### Funciones auxiliares
- masRapido(int algoritmoMasRapido, double tiempoMasRapido): Imprime el algoritmo más rápido y su tiempo de ejecución.
- carrera(int set, vector<int>& datos, bool orden): Realiza una "carrera" entre los algoritmos de ordenamiento con diferentes conjuntos de datos.
- generateRandomNumbers(int count, int rangeStart, int rangeEnd): Genera números aleatorios únicos en un rango.
- convertAndShuffle(set<int>& numbersSet): Convierte un conjunto en un vector y desordena los elementos.
- generateRandomData(int countMin, int countMax, int rangeStart, int rangeEnd): Genera un conjunto de datos aleatorio sin repetición.
- generateRandomDuplicatesData(int countMin, int countMax, int rangeStart, int rangeEnd): Genera un conjunto de datos aleatorio con posibilidad de duplicados.
- generateOrderedData(int countMin, int countMax, int startValue, bool ascending): Genera un conjunto de datos ordenado (ascendente o descendente).
- generateObjectData(int categoryCount, int objectCountMin, int objectCountMax): Genera un conjunto de datos con variación de objetos por categoría.
- generateRaceData(const vector<int>& objectData, bool randomize, bool allowDuplicates, bool ascendingOrder): Genera un conjunto de datos de carrera a partir de un conjunto de objetos.

## Uso del programa

El programa comienza generando conjuntos de datos para diferentes escenarios, como tableros de puntaje, caminos entre aldeas y objetos por categoría. Luego, realiza una "carrera" entre los algoritmos de ordenamiento en diferentes configuraciones de datos (aleatorios, duplicados, ordenados, inversamente ordenados).

#### Selección de la carrera:
El programa solicitará al usuario que elija el tipo de carrera:
    '1' para orden ascendente.
    '2' para orden descendente.

#### Resultados de las Carreras:
Se imprimirán los tiempos de ejecución de cada algoritmo en diferentes conjuntos de datos para los escenarios mencionados anteriormente.

#### Ganador de la carrera:
Se anunciará el algoritmo más rápido y su tiempo de ejecución.

