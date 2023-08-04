#include <iostream>
#include <pthread.h>
#include <vector>

using namespace std;

// Estructura para pasar los argumentos a la función de suma del hilo
struct ThreadArgs {
    vector<int> *array;//arreglo
    int startIndex;
    int endIndex;
    int result;
};

// Función que realiza la suma de un segmento del arreglo en un hilo
void *sumaHilos(void *args) {//puntero genero por usar pthread_create

    ThreadArgs *threadArgs = (ThreadArgs *)args;//
    int sum = 0;
    for (int i = threadArgs->startIndex; i <= threadArgs->endIndex; ++i) {
        sum += (*threadArgs->array)[i];
    }
    threadArgs->result = sum;
    pthread_exit(NULL);
}

int main() {
    const int arraySize = 12; // Tamaño del arreglo
    const int numThreads = 4;  // Número de hilos a utilizar
    vector<int> array(arraySize);

    // Inicializamos el arreglo con valores del 1 al 100
    for (int i = 0; i < arraySize; ++i) {
        array[i] = i + 1;
    }

    // Creamos un arreglo de hilos
    pthread_t threads[numThreads];
    //argumentos
    ThreadArgs threadArgs[numThreads];
    int elementsPerThread = arraySize / numThreads;
    int remainingElements = arraySize % numThreads;

    int startIndex = 0;
    for (int i = 0; i < numThreads; ++i) {
        threadArgs[i].array = &array;
        threadArgs[i].startIndex = startIndex;
        threadArgs[i].endIndex = startIndex + elementsPerThread - 1 + (i < remainingElements ? 1 : 0);
        startIndex = threadArgs[i].endIndex + 1;
        //ejecutar el hilo en paralelo
        //recien como argumento el hilo, usamos atributos por defecto en NULL,
        //la funcion, y los arguemtnso
        pthread_create(&threads[i], NULL, sumaHilos, &threadArgs[i]);
    }
    // Esperamos a que todos los hilos terminen
    for (int i = 0; i < numThreads; ++i) {
        pthread_join(threads[i], NULL);
    }
    // Sumamos los resultados de los hilos
    int totalSum = 0;
    for (int i = 0; i < numThreads; ++i) {
        totalSum += threadArgs[i].result;
    }
    cout << "La suma de todos los elementos del arreglo es: " << totalSum << endl;
    return 0;
}
