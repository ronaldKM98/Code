#include "Nodo.h"

using namespace std;

Nodo::Nodo (string val, Nodo ant, Nodo sig):
 val(val){}
 ant(ant){}
 sig(sig){}

 Nodo::Nodo (){}
 
Nodo::~Nodo() {
	try {
		delete val;
		delete ant;
		delete sig;
	}catch(...) {}
}
string
Nodo::getValor() const {
	return val;
}
Nodo
Nodo::getAnt () const {
	return ant;
}
Nodo
Nodo::getSig () const {
	return sig;
}
void
Nodo::setVal (string val) {
	this.val* = val;
}
void
Nodo::setAnt (Nodo ant) {
	this.ant* = ant;
}
void
Nodo::setSig (Nodo sig) {
	this.sig* = sig;
}