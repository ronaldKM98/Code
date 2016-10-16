#include <iostream>
#include <stdio.h>
#include "diccionario.h"
#include <fstream>

bool load (char* dictionary);
void insert (void);
Node* root;
int dictionary_size = 0;
char [] chars = {/, 39, &,
		 a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,
		 A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,
                 48,49,50,51,52,53,54,55,56,57};


int main () {
  
  return 0;
}



bool load (char* dictionary) {
  ifstream file ("words.txt");
  ifstream* filePtr = &fe;
  
  if (file == NULL) {
    return false;
  }
  
  //Reserva un espacio de memoria para el nuevo objeto
  root = calloc (1, sizeof(Node))
    if (root == NULL) {
      file.close();
      return false;
    }

  Node* cursor = root;
  //Recorre el archivo caracter a caracter
  for (int c = fgetc(filePtr); c != -1; c = fgetc(filePtr)) {
    //si caracter es /n es porque hay una palabra sino ...
    if (c != '/n') {
      //OJO
      for (int i = 0; i < ALPHABET; i++) {
	if (c == chars[i]) {
	  int index =  c;
	}
      }
      // si el nodo es nulo, hay que crear uno nuevo
      if (cursor->arr[index] == NULL) {
	cursor->arr[index] = calloc (1, sizeof(Node));
	if (cursor->arr[index] == NULL) { //Si no nos reserva memoria
	  unload();
	  file.close();
	  return false;
	}
      }
      //si el nodo no es nulo es porque el subTrie existe, entonces no hay que crearlo
      //Es como padar al siguiente nodo (c++)
      cursor = cursor->arr[index];
    }else { //es /n, por por tanto hay una nueva palabra
      cursor->word = true;
      cursor = root;
      dictionary_size++;
    }
  }
  //es posible que hallan errores en la lectura
  if (ferror(filePtr)) {
    unload();
    file.close();
    return false;
  }
  //Terminamos de leer. cerramos el archivo.
  file.close();
  return true;
}
