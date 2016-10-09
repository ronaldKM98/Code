#pragma once
#include <string>
class Nodo {
public:
	 Nodo(string val, nodo ant, nodo sig);
	 Nodo();
	~ Nodo();
	string getValor const ();
	Nodo getSig const ();
	void setVal (string val);
	void setAnt (nodo ant);
	void setSig (nodo sig);
private:
	string val;
	nodo ant, sig;
};