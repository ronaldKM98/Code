#include "diccionario.h"
#include <iostream>
#include <stdio.h>
#include <cctype>
#include <stdlib.h>
#include <cstdio>
#include <string.h>
#include <string>
#include <fstream>
#define ALPHABET 39

using namespace std;

bool load (char* dictionary);
bool search (char word [], Node* actual);
void autocomplete (char* str);
//bool unload (void);
//void unloader (Node* cursor);
unsigned int getSize (void);
Node* root;
int MAX = 256;
int dictionary_size = 0;
char chars [ALPHABET] = {'/', 39, '&',
     'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
                 48,49,50,51,52,53,54,55,56,57};

int main (void) {
  // en el main ninguna funcion puede ser llamada antes de load
  // si se hace va a sacar error!
  char* dictionary;
  if (load(dictionary)) {
    //cout << "Cargo " << getSize() << " palabras" << endl;
  }else {
    //cout << "Error cargando" << endl;
  }

  char word [MAX + 1];
  cin.getline(word, MAX);
  Node* act;
  if (search(&word[0], act)) {
    cout << "true" << endl;
  }else {
    cout << "false" << endl;
  }
}


bool load (char* dictionary) {
  //Esta funcion carga todo el diccionario en el trie cuando ejecutamos el programa.
  FILE* filePtr;
  filePtr = fopen ("words.txt", "r");
  if (filePtr == NULL) {
    return false;
  }
  
  //Reserva un espacio de memoria para el nuevo nodo, 
  //calloc devuelve void* que se puede pasar a cualquier tipo
  root = (Node*) calloc(1, sizeof(Node));
    if (root == NULL) {
      //unload();
      fclose (filePtr);
      return false;
    }    

  Node* cursor = root;
  int index;
  //Recorre el archivo caracter a caracter
  for (char caracter = fgetc(filePtr); caracter != -1; caracter = fgetc(filePtr)) {
    caracter = tolower(caracter);
    //si caracter es /n es porque hay una palabra sino ...
    if (caracter != '\n') {
      //OJO
      for (int i = 0; i < ALPHABET; i++) {
          if (caracter == chars[i]) {
            index = i;
          }
      }
      // si el nodo es nulo, hay que crear uno nuevo
      if (cursor->arr[index] == NULL) {
        cursor->arr[index] = (Node*) calloc (1, sizeof(Node));
          if (cursor->arr[index] == NULL) { //sigue siendo nulo
  //            unload();
              fclose(filePtr);
              return false;
          }
        cursor->c = caracter;
        cursor->frecuencia = 0;
      }
      // Si el nodo no es nulo es porque el subTrie existe, entonces no hay que crearlo
      // Es como pasar al siguiente nodo (nodo++)
      cursor = cursor->arr[index];
    }else { //es /n, entonces hay una nueva palabra
      cursor->word = true;
      cursor = root;
      ++dictionary_size;
    }
  }
  //es posible que hallan errores en la lectura
    if (ferror(filePtr)) {
    //  unload();
      fclose(filePtr);
      return false;
    }

  //Terminamos de leer. Cerramos el archivo. :D
  fclose(filePtr);
  return true;
}


bool search (char* word, Node* actual) {
  //Esta funcion busca una palabra en la estructura
  //el parametro Node* es para que nos devuelva el nodo final de la busqueda ind/
  // de si fue exitosa o  no. Para poder continuar con la funcion autocompletar
  Node* cursor = root;
  int index;
//Recorrer la palabra caracter a caracter
  for (int i = 0; i < strlen(word); i++) {
      //hallar el indice del caracter en el arreglo de caracteres
    for (int j = 0; j < ALPHABET; j++) {
      //char caracter = tolower(word[i]);
        if (tolower(word[i]) == chars[j]) {
          index = j;
          //cout << index << endl;
          break;
        }
    }
          // el siguiente nodo que deberia existir
          //no existe, entonces no hay palabra
          if (cursor->arr[index] == NULL) {
            //cout << "No existe el nodo" << endl;
              return false;
          }else {
            //cout << "Si existe, entonces vamos a ese nodo" << endl;
            cursor = cursor->arr[index];
          }
  }

  //Se termino la palabra
  //retornamos el valor booleano de la posicion actual
  //cout << cursor->word << endl;
   actual = cursor;
   if (cursor->word) {
    cursor->frecuencia += 1;
    return true;
   }
}

void autocomplete (char* str) {
  int index;
  Node* cursor; 
  search(&str[0], cursor);
  //Ya tenemos el nodo donde se termina la cadena
  //ahora hay que imprimir todo el arbol que hay debajo de ese nodo;
  for (int i = 0; i < ALPHABET; i++) {

  } 
}

//bool unload (void) {
  //unloader(root);
//  return true;
//}

//void unloader (Node* cursor) {
  //Esta funcion va a liberar la memoria usada por el programa
  //for (int i = 0; i < ALPHABET; i++) {
    //if (cursor->arr[i] != NULL) {
      //unloader(cursor->arr[i]);
    //}
  //}
  //free(cursor);
//}

unsigned int getSize (void) {
  return dictionary_size;
}