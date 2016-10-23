//El fuckin' bug es: que no acepta palabras largas
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "diccionario.h"
#include <cstdio>
#include <fstream>
#define ALPHABET 66

using namespace std;

bool load (char* dictionary);
void insert (void);
unsigned int getSize (void);
Node* root;
int dictionary_size = 0;
char chars [ALPHABET] = {'/', 39, '&',
     'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
     'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
                 48,49,50,51,52,53,54,55,56,57};


int main () {
  char* dictionary;
  if (load(dictionary)) {
    cout << "Cargooooooooo! FUCKKKK" << endl;
    return 0;
  }
  cout << "FALSE" << endl;
  return 0;
}

bool load (char* dictionary) {
  FILE* filePtr;
  filePtr = fopen ("words.txt", "r");
  if (filePtr == NULL) {
    return false;
  }
  
  //Reserva un espacio de memoria para el nuevo nodo, 
  //calloc devuelve void* que se puede pasar a cualquier tipo
  root = (Node*) calloc(1, sizeof(Node));
    if (root == NULL) {
      fclose (filePtr);
      return false;
    }

  Node* cursor = root;
  int index;
  //Recorre el archivo caracter a caracter
  for (int c = fgetc(filePtr); c != -1; c = fgetc(filePtr)) {
    //si caracter es /n es porque hay una palabra sino ...
    if (c != '\n') {
      //OJO
      for (int i = 0; i < ALPHABET; i++) {
  if (c == chars[i]) {
    index =  c;
  }
      }
      // si el nodo es nulo, hay que crear uno nuevo
      if (cursor->arr[index] == NULL) {
  cursor->arr[index] = (Node*) calloc (1, sizeof(Node));
  if (cursor->arr[index] == NULL) { //Si no nos reserva memoria
    //    unload();
    fclose(filePtr);
    return false;
  }
      }
      //si el nodo no es nulo es porque el subTrie existe, entonces no hay que crearlo
      //Es como padar al siguiente nodo (nodo++)
      cursor = cursor->arr[index];
    }else { //es /n, entonces hay una nueva palabra
      cout << "Creando palabra " << dictionary_size << endl;
      cursor->word = true;
      cursor = root;
      dictionary_size++;
    }
  }
  //es posible que hallan errores en la lectura
  if (ferror(filePtr)) {
    //unload();
    fclose(filePtr);
    return false;
  }
  //Terminamos de leer. Cerramos el archivo. :D
  fclose(filePtr);
  return true;
}

unsigned int getSize (void) {
  return dictionary_size;
}
