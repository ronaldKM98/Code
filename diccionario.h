#pragma once
#define ALPHABET 39
typedef struct Node {
  bool word;
  int frecuencia;
  char c;
  struct Node* arr [ALPHABET];
}
	Node;