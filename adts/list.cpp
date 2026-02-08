#pragma once 

template <class T>
class List{
    public:
    virtual void add(T data) = 0;
    virtual T get(int pos) = 0;
    virtual bool contains(T data) = 0;
    virtual bool isEmpty() = 0;
    virtual int size() = 0;
    virtual void remove(T data) = 0;
};
