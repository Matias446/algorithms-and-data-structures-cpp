#pragma once
#include "ColaPrioridadInt.cpp"
#include "pair.cpp"

template <class T, class P>
class colaPriodidad : public cola_prioridadInt<T>
{
private:
  Pair<T, P>* arr;
  int cant;
  int largoArr;

public:
	virtual cola_prioridadInt crearcola_prioridadInt(unsigned int cota) override {
	cola_prioridadInt colaP = new _cabezalcola_prioridadInt;
	colaP->ppio = nullptr;
	colaP->fin = nullptr;
	colaP->cota = cota;
	colaP->largo = 0;
	return colaP;
	}

	virtual void encolar(int e, int p) override {
	Nodo nuevo = new _nodoLista;
	nuevo->dato = e;
	nuevo->prio = p;
	nuevo->sig = nullptr;

	if (!esVacia(c)) {
		if (c->fin->prio >= p) {
			// insertar al final
			c->fin->sig = nuevo;
			c->fin = nuevo;
		}
		else if (c->ppio->prio < p) {
			// insertar al principio
			nuevo->sig = c->ppio;
			c->ppio = nuevo;
		}
		else {
			// insertar en el medio
			_nodoLista* aux = c->ppio;
			while (aux->sig != nullptr && aux->sig->prio >= p) {
				aux = aux->sig;
			}
			nuevo->sig = aux->sig;
			aux->sig = nuevo;
			if (nuevo->sig == nullptr) {
				c->fin = nuevo;
			}
		}
	}
	else {
		c->ppio = nuevo;
		c->fin = nuevo;
	}
	c->largo++;
	}

	virtual int principio() override {
	return c->ppio->dato;
	}

	virtual int principioPrioridad() override {
	return c->ppio->prio;
	}

	virtual void desencolar() override{
	if (c->largo == 0) return;
	_nodoLista* aBorrar = c->ppio;
	c->ppio = c->ppio->sig;
	if (c->ppio == nullptr) {
		c->fin = nullptr;
	}
	delete aBorrar;
	c->largo--;
	}	

	virtual bool esVacia() override {
	return c->largo == 0;
	}

	virtual bool esLlena() override {
	return c->largo == c->cota;
	}

	virtual unsigned int cantidadElementos() override {
	return c->largo;
	}
};
