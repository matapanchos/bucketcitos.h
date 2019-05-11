#include <iostream>
#include <fstream>
#include <iomanip>
#include <chrono>
#include <vector>

using namespace std;

template <typename M>
double prom_array(vector<M> arr) {
    double promedio = 0;
    for (int i = 0; i < arr.size(); i++) {
        promedio += arr[i];
    }
    promedio /= arr.size();
    return promedio;
}

template <typename T>
double timer(T (*funcion)(T), T arg, int num_tests) {
    vector<double> promarr;
    int i = 0;
    chrono::time_point<chrono::high_resolution_clock> start, end;
    while (i < num_tests) {
        start = chrono::high_resolution_clock::now();
        T f = funcion(arg);
        end = chrono::high_resolution_clock::now();

        chrono::duration<double> runtime = end - start;
        promarr.push_back(runtime.count());
        i++;
    }

    return prom_array(promarr);
}

void createfile(string filename, vector<double> time, int arg) {
    fstream file;
    file.open(filename, ios::app);

    if (!file) { 
        cout << "Error in creating file" << endl;
        return;
    }
    for (int i = 0; i < time.size(); i++) {
        if (i == 0)
            file << arg << " ";
        if (i != time.size() - 1)
            file << fixed << setprecision(10) << time[i] << " ";
        else
            file << fixed << setprecision(10) << time[i] << endl;
    }
    file.close();
}
