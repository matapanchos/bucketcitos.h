#include <iostream>
#include <fstream>
#include <iomanip>
#include <chrono>
#include <vector>

using namespace std;

template <typename T>
double timer(T (*funcion)(T), T arg) {
    auto start = chrono::high_resolution_clock::now();
    T f = funcion(arg);
    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double> runtime = end - start;
    return runtime.count();
}

void createfile(string filename, vector<double> time, int n) {
    fstream file;
    file.open(filename, ios::app);

    if (!file) { 
        cout << "Error in creating file" << endl;
        return;
    }
    
    for (int i = 0; i < time.size(); i++) {
        if (i == 0)
            file << n << " ";
        if (i != time.size() - 1)
            file << fixed << setprecision(10) << time[i] << " ";
        else
            file << fixed << setprecision(10) << time[i] << endl;

    }
    file.close();
}
