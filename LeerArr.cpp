//
// Created by RONALD on 08/10/2016.
//
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

void leerArr () {
    ifstream fin ("words.txt");
  string aux;
  int CANT = 354985;
  string palabras [CANT];
  int i = 0;
  while (fin >> aux) {
      palabras [i] = aux;
      cout << palabras[i] << endl;
      i++;
    }
}