#ifndef TIME_H
#define TIME_H
#include <iostream>
#include <string>
#include <chrono>
#include <fstream>
using namespace std;

void Time(long int (*func)(int),int arg, ofstream &file, string name, int n){

  auto start = std::chrono::high_resolution_clock::now();
  auto rpta=func(arg);
  // func(arg);
  auto stop = std::chrono::high_resolution_clock::now();
  chrono::duration<double> time =(stop - start);
  // cout << name<<" time : "<<  std::chrono::duration_cast<std::chrono::nanoseconds>(time).count()<< endl;
  cout << name << " = " << rpta<<" with time : "<<  std::chrono::duration_cast<std::chrono::nanoseconds>(time).count()<< endl;
  if(n==0){
    file<<std::chrono::duration_cast<std::chrono::nanoseconds>(time).count()<<",";
  }
  else{
    file<<std::chrono::duration_cast<std::chrono::nanoseconds>(time).count()<<endl;
  }

}

#endif
