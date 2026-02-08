#ifndef COLA_PRIORIDAD_INT_H
#define COLA_PRIORIDAD_INT_H

template <class T>
class cola_prioridadInt
{
public:
    // pre:
    // post: the element is inserted at the end of the list
    virtual void encolar(T element, int priority) = 0;

    // pre: -
    // post: returns the first element of the list
    virtual T principio() = 0;

    // pre: -
    // post: returns the first priority of the list
    virtual int principioPrioridad() = 0;

    // pre: -
    // post: removes the first element of the list
    virtual void desencolar() = 0;

    // pre: -
    // post: returns if the list is empty
    virtual bool esVacia() = 0;

    // pre: -
    // post: returns if the list is full
    virtual bool esLlena() = 0;

    // pre: -
    // post: returns the size of the list
    virtual unsigned int cantidadElementos() = 0;
};

#endif
