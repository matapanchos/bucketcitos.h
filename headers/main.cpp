#include <iostream>
#include <chrono>
#include <iomanip>
#include <map>
#include "createf.h"

using namespace std;

int n;

int rFibonacci(int n){
    if (n == 0 || n == 1)
        return n;
    else
        return rFibonacci(n - 1) + rFibonacci(n - 2);
}

int iFibonacci(int n){
    int a  = 0, b = 1, c;
    for (int i = 0; i < n; ++i){
        c = b + a;
        a = b;
        b = c;
    }
    return a;
}

int main()
{    
    cin >> n; 
    vector<double> time;
    time.push_back(timer(*rFibonacci, n, 1000));
    time.push_back(timer(*iFibonacci, n, 1000));
    createfile("data.txt", time, n);
    return 0;
}
