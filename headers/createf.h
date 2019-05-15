#include <iostream>
#include <fstream>
#include <iomanip>
#include <chrono>
#include <vector>

using namespace std;

// Te devuelve variable tipo double del promedio de los valores de tu vector
template <typename M>
double prom_array(vector<M> arr) { // pasas el vector
    double promedio = 0;
    for (int i = 0; i < arr.size(); i++) { // suma todos los valores del vector
        promedio += arr[i];
    }
    promedio /= arr.size(); // divide para hacer el promedio
    return promedio;
}

// funcion que devuelve el tiempo promedio de correr una función y tu pones cuantass test quieres que haga
template <typename T>
double timer(T (*funcion)(T), T arg, int num_tests) {
    vector<double> promarr;
    int i = 0;
    chrono::time_point<chrono::high_resolution_clock> start, end; // declaracion de variables inicio y fin 
    while (i < num_tests) {
        start = chrono::high_resolution_clock::now();
        T f = funcion(arg);
        end = chrono::high_resolution_clock::now();

        chrono::duration<double> runtime = end - start; // el tiempo de correr la función una vez
        promarr.push_back(runtime.count()); // ingresa el tiempo en el vector
        i++;
    }

    return prom_array(promarr); // devuelve valor promedio de todos tiempos 
} 

// crea un file donde tu le pones nombre y te escribe en él la primera linea
// debes tener un vector de tiempos de funcion que puedes obtener con la funcion de arriba
void createfile(string filename, vector<double> time, int arg) {
    fstream file;
    file.open(filename, ios::app); // ios::app es que siempre te inserte al final de una linea

    if (!file) { // si hay problemas en crar el file te bota una alerta 
        cout << "Error in creating file" << endl;
        return;
    }
    for (int i = 0; i < time.size(); i++) {
        if (i == 0) // escribe el argumento que pusiste de tu funcion al principio de linea
            file << arg << " ";
        if (i != time.size() - 1)
            file << fixed << setprecision(10) << time[i] << " "; // escribe los tiempos que tienes separados por espacio
        else
            file << fixed << setprecision(10) << time[i] << endl; // cuando es el ultimo tiempo en tu vector hace un salto de línea
    }
    file.close(); // cierra el archivo
}
