#pragma once
#define ALPHABET 39


	/**
	@author Natalia Arias
	@author Ronald Cardona
	*/
	/**
 	Este archivo, tiene la definicion de la estructura Nodo que corresponde
 	a la estructura de datos usada.
	
	*/

struct Node {
  bool word;
  int frecuencia;
  char c;
  Node* arr [ALPHABET];
};