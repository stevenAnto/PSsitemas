#include <iostream>
#include <vector>
#include <future>
using namespace std;

int suma(int nums[], int start, int end) {
    int total = 0;
    for (int i = start; i < end; i++) {
        total += nums[i];
    }
    return total;
}

int main() {
    int numeros[] = {1, 2, 3, 4, 5,6,7};
    int size = sizeof(numeros) / sizeof(numeros[0]);

    //controlando el numero de hilos y el tamanio de subconjuntos que cada hilo hara
    int num_hilos = 3;
    int tam_subconjunto = size / num_hilos;
    cout<<"tam_subconjunto "<<tam_subconjunto<<endl;

    //futuros usado para almacenar lso resultados de la funcion suma
    //future es una clase que permite acceder a datos de manera asincrona
    vector<future<int>> futuros;
    //almacena los resultados finales de cada hilo
    vector<int> resultados(num_hilos);

    // Crear los futuros y asignar subconjuntos del arreglo a cada hilo
    for (int i = 0; i < num_hilos; i++) {
        int inicio = i * tam_subconjunto;
        int fin = (i == num_hilos - 1) ? size : inicio + tam_subconjunto;
        futuros.emplace_back(async(suma, numeros, inicio, fin));
    }

    // Recuperar los resultados de los futuros y almacenarlos en el vector resultados
    for (int i = 0; i < num_hilos; i++) {
        resultados[i] = futuros[i].get();
    }

    // Combinar los resultados de los hilos
    int suma_total = 0;
    for (int i = 0; i < num_hilos; i++) {
        suma_total += resultados[i];
    }

    cout << "La suma de los primeros " << size << " numeros es " << suma_total << endl;

    return 0;
}
