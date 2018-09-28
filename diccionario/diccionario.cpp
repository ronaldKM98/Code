#include "diccionario.h"
#include <iostream>
#include <stdio.h>
#include <cctype>
#include <stdlib.h>
#include <cstdio>
#include <string.h>
#include <string>
#include <cstring>
#include <vector>
#include <fstream>
#include <list>
#include <cmath>
#include <time.h>
#include <stdio.h>
#define ALPHABET 39

using namespace std;

/**
@author Natalia Arias
@autor Ronald Cardona
@date 12/11/16
*/


/** fin y fout son dos flujos, uno de entrada y otro de salida, para leer
    y escribir el archivo frecuencias.txt, que es donde se guarda el
    atributo frecuencia de cada nodo
*/
fstream fin("frecuencias.txt");
ofstream fout("frecuencias.txt");
/** Inicio del arbol */
Node* root;

bool load ();
bool search (char* word, Node* actual);
void saveFrecuency (Node* root); 
void cat (char*);
char getC (Node*);
unsigned int getSize (void);
string getCode (char str []);
Node* getChildren (Node*, int);
list<string> autocomplete (Node*);
vector<string> compare (string);
vector<string> comparacionRecursiva (Node*, vector<int>, int, string, string, int);

int MAX = 256;
int dictionary_size = 0;

/** Caracteres pertenecientes al alfafeto */
char chars [ALPHABET] = {'/', 39, '&',
      'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
      48,49,50,51,52,53,54,55,56,57};

int main (void) {

  //char* dictionary;

  clock_t start, end;
  start = clock();
   load();
  end = clock();
  double secs = (double) (end - start) / CLOCKS_PER_SEC;
  cout << "Tiempo de carga (s) " << secs << endl;

  menu: cout << "Menu" << endl;
  cout << "1- Buscar palabra en el diccionario " << endl;
  cout << "2- Autocompletar " << endl;
  cout << "3- Comparacion fonetica " << endl;
  cout << "4- Terminar " << endl;

  int m;
  cin >> m;
  switch(m) {
  case 1:
    while (true) {
      char word [MAX + 1];
      cout << "Ingrese palabra a buscar " << endl;
      cin >> word;
      Node* act = (Node*) calloc(1, sizeof(Node));

      clock_t ini, fin;
      ini = clock();
        if (search(&word[0], act)) {
          cout << "true" << endl;
          //cout << getCode(word) << endl;
        }else {
          cout << "false" << endl;
        }
      fin = clock();
      double t = (double) (fin - ini) / CLOCKS_PER_SEC;
      cout << "Tiempo (s) " << t << endl;
    }

    case 2:
    while (true) {
      char word2 [MAX + 1];
      cout << "Ingrese un prefijo " << endl;
      cin >> word2;
      cat(word2);
    }

    case 3:
    while (true) {
      Node* n = (Node*) calloc(1, sizeof(Node));
      char word3 [MAX + 1];
      cout << "Ingrese una palabra " << endl;
      cin >> word3;

      clock_t ini, fin;
      ini = clock();

      if (!search(&word3[0], n)) {
        cout << "La palabra no fue encontrada " << endl;
      }else {
        vector<string>coincidencias = compare(&word3[0]);
        int cont = 0;
        for(int i = 0; i < coincidencias.size(); i++) {
          string p = coincidencias[i];
          int a = p.length() - strlen(word3);
          if (a == 0 || abs(a) < 2) {
            cont++;
             cout << coincidencias[i] << endl;
          }
        }
        cout << cont << " Similitudes" << endl;
      }
      fin = clock();
      double t = (double) (fin - ini) / CLOCKS_PER_SEC;
      cout << "Tiempo (s) " << t << endl;
    }

    case 4:
      return 0;
  }
  return 0;
}

/** Trae la totalidad de las palabras del archivo, y las carga cada una
    en el arbol.
    @return booleano que indica si la carga fue exitosa
    */
bool load () {
  FILE* filePtr;
  filePtr = fopen ("words.txt", "r");

  if (filePtr == NULL) {
    return false;
  }

  //Reserva un espacio de memoria para el nuevo nodo,
  //calloc devuelve void* que se puede pasar a otro tipo
  root = (Node*) calloc(1, sizeof(Node));
    if (root == NULL) {
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
      fin >> cursor->frecuencia;
      cursor = root;
      ++dictionary_size;
    }
  }
  //es posible que hallan errores en la lectura del archivo
    if (ferror(filePtr)) {
      fclose(filePtr);
      return false;
    }

  //Terminamos de leer. Cerramos el archivo.
  fclose(filePtr);
  return true;
}

/**Busca busca una palabra en el dicionario
@param referencia a un caracter que representa el primer caracter de la palabra
@return booleano que indica si la palabra esta en el diccionario
*/
bool search (char* word, Node* actual) {

  Node* cursor = root;
  int index;
//Recorrer la palabra caracter a caracter
  for (int i = 0; i < strlen(word); i++) {
    //hallar el indice del caracter en el arreglo de caracteres
    for (int j = 0; j < ALPHABET; j++) {
      if (tolower(word[i]) == chars[j]) {
        index = j;
        break;
      }
    }

    // el siguiente nodo que deberia existir
    //si no existe, entonces no hay palabra
    //actual = cursor->arr[index];
    if (cursor->arr[index] == NULL) {
      //No existe el nodo
      return false;
    }else {
      //Si existe, entonces vamos a es nodo
      cursor = cursor->arr[index];
    }
  }

  //Se termino la palabra
  //retornamos el valor booleano del nodo actual
    actual = cursor->arr[index];
   if (cursor->word) {
    cursor->frecuencia += 1;
    //cout <<"Nro de veces buscada : " << cursor->frecuencia << endl;
    return true;
   }
   return false;
}

/**Busca cadenas de strings que formen palabras y que esten debajo
del nodo que se pasa como parametro
@param Referencia a un nodo del arbol
@return Lista de tipo string
*/
list<string> autocomplete (Node* cursor) {
  list <string> words;
  Node* children [ALPHABET]; //(Node*) calloc(1,sizeof(Node[ALPHABET]));

  for (int i = 0; i < ALPHABET-1; i++) {
    if (cursor->arr[i] != NULL) {
      cout << " no es nulo " << i << endl;
      children[i] = cursor->arr[i];
    }else  {
      cout << " es nulo" << endl;
      children[i] = (Node*) calloc(1, sizeof(Node));
    }
  }

  for (int i = 0; i < ALPHABET - 1; i++) {
    Node* child = children[i];
    if (child == 0) {
      cout << "Paso por nulo" << endl;
      continue;
    }else {
      string word = "";
      cout << child->c << endl;
      word = word + child->c;
      cout << "Palabra es " << word << endl;
      if (child->word) {
        cout << " ENTRO, AÑADIENDO COINCIDENCIA " << endl;
          words.push_back(word);
      }

      list <string> leftOver = autocomplete(child);

      // cout << leftOver.size() << endl;
      if (leftOver.size() > 0) {
        for (int i = 0; i < leftOver.size(); i++) {
          words.push_back(word + leftOver.back());
        }
      }
    }
  }
  return words;
}

/** Concatena e imprime el string ingresado que es el prefijo, con
  un sufijo que seria la palabra que se trajo desde la funcion autocompletar
  @param Referencia al primer caracter de la palabra que se va a autocompletar
  */
void cat (char word []) {
  Node act;
  search(&word[0], &act);
  list<string> words;
  string str(word);

  if (&act != NULL) {
    words.push_back(str);
    list<string> leftOver = autocomplete(&act); //Las funciones propias de la lista no estan bien;
    if (leftOver.size() > 0) {
      for (list<string>::iterator it = leftOver.begin(); it != leftOver.end(); ++it) {
        words.push_back(str + *it);
        cout << words.back() << *it << endl;
      }
    }
    cout << "No hay coincidencias para " << str << endl;
  }
}

/**Compara foneticamente por medio del algoritmo de Leveshtein Distance
    con una constante DIST (k) de diferencias entre una palabra y otra.
    @param Palabra para hallar similitudes
    @return lista de tipo string con las palabras similares a la ingresada
*/
vector<string> compare (string str) {
  int DIST = 1;
  vector<int> linea;
  vector<string> resultados;
  for (int i = 0; i < str.length(); i++) {
    linea.push_back(i);
  }
  for (int i = 0; i < ALPHABET; i++) {
    if (root->arr[i] == NULL) {
      continue;
    }

    vector<string> parcial = comparacionRecursiva (root->arr[i], linea, DIST, str, "", i);
    resultados.insert(resultados.end(), parcial.begin(), parcial.end());
  }
    return resultados;
}

/**
     * Compara las palabras fonéticamente con Levenshtein Distance
     * @param Cursor el nodo donde termian la palabra.
     * @param lineaAnterior línea anterior de la matriz para realizar Levenshtein distance.
     * @param constMax los cambios que necesita una palabra para convertirse en la ingresada.
     * @param str palabra ingresada para buscar similitudes.
     * @param palabraParcial la palabra que se va formando en cada llamada recursiva
     * @param letraIndex indice del caracter donde termina la palabra en el alfabeto
     * @return una lista de Strings con las posibles comparaciones fonéticas de la palabra ingresada.
     */
vector<string> comparacionRecursiva (Node* cursor, vector<int> lineaAnterior, int constMax, string str, string palabraParcial, int letraIndex) {
  vector<int> lineaActual;
  vector<string> resultados;


    lineaActual.push_back(lineaAnterior.front() + 1);

  int costo = 0;
  int tamPalabra = str.length();

  for (int i = 1; i <= tamPalabra; i++) {
    int index;
    for (int j = 0; j < ALPHABET; j++) {
      if (tolower (str[i - 1]) == chars[j]) {
        index = j;
      }
    }
    if (index == letraIndex) {
      costo = lineaAnterior[i - 1];
    }
    else {
      costo = fmin(lineaAnterior[i], lineaAnterior[i - 1]);
      costo = fmin(costo, lineaActual[i - 1]) + 1;
    }
    lineaActual.push_back(costo);
  }

  int costoLinea = lineaActual[tamPalabra];
  string palabraFinal = palabraParcial + chars[letraIndex];

  if (costoLinea <= constMax && cursor->word) {
    resultados.push_back(palabraFinal);
  }

  int min = 10;
  for (int i = 0; i < lineaActual.size() - 1; i++) {
    int a = fmin(lineaActual[i], lineaActual[i + 1]);
    if (a < min) {
      min = a;
    }
  }

  if (min <= constMax) {
    Node* children [ALPHABET];
    memcpy(children, cursor->arr, sizeof(Node*[ALPHABET]));

    for (int i = 0; i < ALPHABET; i++) {
      if (children[i] == NULL) {continue;}
      vector<string> resultadosParciales = comparacionRecursiva(children[i], lineaActual,
                                                        constMax, str, palabraFinal, i);

      if (resultadosParciales.size() > 0) {
        resultados.insert(resultados.end(), resultadosParciales.begin(), resultadosParciales.end());
      }
    }
  }
  return resultados;
}

/** Permite conocer la cantidad de palabras pertenecientes al diccionario
@return Numero de palabras del diccionario
*/
unsigned int getSize (void) {
  return dictionary_size;
}

/**Guarda el atributo frecuencia de cada nodo que represente una palabra
  en el archivo frecuencias.txt, para poder recuperar esos datos en una
  futura ejecucion
*/
void saveFrecuency (Node* cursor) {
  int i = 0;
  while (i < ALPHABET) {
    if (&cursor != NULL)  {
        if (cursor->word) {
        fout << cursor->frecuencia;
      }
      cursor = cursor->arr[i];
      saveFrecuency(cursor);
    }
    i++;
  }
}