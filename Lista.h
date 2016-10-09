#pragma once
#include "Nodo.h"
#include "string"
class Lista {
public:
	 Lista(Nodo inicial, int size);
	~ Lista();
	bool empty () const;
	void insertarInicio (string val);
	void insertarPos (int pos, string val);
	void eliminar (int pos);
	void listar();
	string recuperar (int pos, Lista lista);
	int getSize () const;
	string buscar (string val);
};