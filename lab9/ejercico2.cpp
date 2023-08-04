#include <iostream>
#include <pthread.h>
#include <vector>
#include <limits>

using namespace std;

// Estructura para pasar los argumentos a la función del hilo
struct ThreadArgs {
    vector<int> *array;
    int startIndex;
    int endIndex;
    int max;
};

// Función que busca el valor máximo en un segmento del arreglo
void *maxThread(void *args) {
    ThreadArgs *threadArgs = (ThreadArgs *)args;
    int max = numeric_limits<int>::min();
    for (int i = threadArgs->startIndex; i <= threadArgs->endIndex; ++i) {
        if ((*threadArgs->array)[i] > max) {
            max = (*threadArgs->array)[i];
        }
    }
    threadArgs->max = max;
    pthread_exit(NULL);
}
void imprimitVector(vector<int> a){
  cout<<"{ ";
  for(auto elemento:a){
    cout<<elemento<<",";
  }
  cout<<"}\n";
}

int main() {
    const int arraySize = 5; // Tamaño del arreglo muy grande
    const int numThreads = 4;      // Número de hilos a utilizar
    vector<int> array(arraySize);

    // Inicializamos el arreglo con valores aleatorios entre 1 y 1000
    for (int i = 0; i < arraySize; ++i) {
        array[i] = rand() % 10 + 1;
    }
    imprimitVector(array);

    // Creamos un arreglo de hilos
    pthread_t threads[numThreads];
    ThreadArgs threadArgs[numThreads];
    int elementsPerThread = arraySize / numThreads;
    int remainingElements = arraySize % numThreads;

    int startIndex = 0;
    for (int i = 0; i < numThreads; ++i) {
        threadArgs[i].array = &array;
        threadArgs[i].startIndex = startIndex;
        threadArgs[i].endIndex = startIndex + elementsPerThread - 1 + (i < remainingElements ? 1 : 0);
        startIndex = threadArgs[i].endIndex + 1;
        pthread_create(&threads[i], NULL, maxThread, &threadArgs[i]);
    }

    // Esperamos a que todos los hilos terminen
    for (int i = 0; i < numThreads; ++i) {
        pthread_join(threads[i], NULL);
    }

    // Buscamos el valor máximo entre los resultados de los hilos
    int maxValue = numeric_limits<int>::min();
    for (int i = 0; i < numThreads; ++i) {
        if (threadArgs[i].max > maxValue) {
            maxValue = threadArgs[i].max;
        }
    }

    cout << "El valor máximo del arreglo es: " << maxValue << endl;

    return 0;
}
