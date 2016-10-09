#include "Lista.h"
#include <string>
#include "Nodo.h"
#include <iostream>
Lista::Lista(Nodo inicial, int size):
	inicial(inicial){}
	size(size){}
	Lista::~Lista() {
		try {
			delete inicial;
			delete size;
		}catch (...) {}
	}
	bool
	Lista::empty () const {
		if (inicial == NULL) {return true}
			return false;
	}
	void
	Lista:: insertarInicio(string val) {
		Nodo nuevo = new Nodo();
		nuevo.setVal (val);
		nuevo.setSig(inicial);
		inicial = nuevo;
		size++;
 	}
 	void
 	Lista::insertarPos (int pos, string val) {
 		Nodo nuevo = new Nodo();
 		nuevo.setVal(val);

 		if (pos == 0) {
 			nuevo.setSig(inicial);
 			inicial = nuevo;
 		}else {
 			Nodo nodoAux = inicial;

 			for (int i = 0; i < pos - 1; ++i) {
 				nodoAux = nodoAux.getSig();
 			}
 			Nodo sig = nodoAux.getSig();
 			nodoAux.setSig(nuevo);
 			nuevo.setSig(sig);
 			size++;
 		}
 	}
 	void
 	Lista::eliminar (int pos) {
 		if (pos == 0) {
 			inicial = inicial.getSig();
 		}else {
 			Nodo nodoAux = inicial;

 			for (int i = 0; i < pos - 1; ++i) {
 				nodoAux = nodoAux.getSig();
 			}
 			Nodo sig = nodoAux.getSig();
 			nodoAux.setSig(sig.getSig());
 			size--;
 		}
 	}
 	void
 	Lista:: listar () {
 		Nodo nodoAux = inicial;
 		while (nodoAux != NULL) {
 			cout << nodoAux.getValor() << endl;
 			nodoAux = nodoAux.getSig();
 		}
 	}
 	string
 	Lista::recuperar (int pos, Lista lista) {
 		Nodo nodoAux, nodoi;
 		if (pos == 0) {
 			return inicial.getValor();
 		}else {
 			nodoAux = inicial;
 			for (int i = 0; i < pos - 1; ++i) {
 				nodoAux = nodoAux.getSig();
 			}
 			nodoi = nodoAux.getSig();
 		}
 		return nodoi.getValor();
 	}
 	//Faltan desde get size hacia abajo

