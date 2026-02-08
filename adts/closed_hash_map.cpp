#pragma once
#include <string>
#include "./pair.cpp"
#include "./linked_list.cpp"
#include "./map.cpp"
#include "../func/hash_func.cpp"


template <class K, class V>
class ClosedHashMap : public Map<K, V>
{
private:
  // List<Pair<K,V>>*[] arr
  List<Pair<K, V>> **buckets;
  int bucketsSize;
  int count = 0;
  bool *deleted;
  HashFunc<K> hashFunc1;
  HashFunc<K> hashFunc2;

  int abs(int x)
  {
    if (x < 0)
    {
      return -x;
    }
    return x;
  }

public:
  ClosedHashMap(int expectedSize){
    // con un factor de carga de ~0,5 
    this->bucketsSize = expectedSize * 2 + 1;
    this->buckets = new List<Pair<K, V>>*[this->bucketsSize];
    this->deleted = new bool[this->bucketsSize];
    for (int i = 0; i < this->bucketsSize; i++)
    {
      this->buckets[i] = nullptr;
      this->deleted[i] = false;
    }
  }


  virtual V get(K key) override {
    int hash1 = hashFunc1.hash(key) % this->bucketsSize;
    int hash2 = hashFunc2.hash2(key) % this->bucketsSize;

    for (int i = 0; i < this->bucketsSize; i++)
    {
      int pos = abs((hash1 + i * hash2) % this->bucketsSize);

      if (this->buckets[pos] != nullptr && !this->deleted[pos])
      {
        return this->buckets[pos]->get(0).snd;
      }
    }
    return V(-1); // Retorna un valor por defecto si no se encuentra la clave
  }

  

  virtual void set(K key, V value) override {
    int hash1 = hashFunc1.hash(key) % this->bucketsSize;
    int hash2 = hashFunc2.hash2(key) % this->bucketsSize;

    for (int i = 0; i < this->bucketsSize; i++)
    {
      int pos = abs((hash1 + i * hash2) % this->bucketsSize);

      if (this->buckets[pos] == nullptr || this->deleted[pos])
      {
        if (this->buckets[pos] == nullptr)
        {
          this->buckets[pos] = new LinkedList<Pair<K, V>>();
        }
        
        this->buckets[pos]->add(Pair<K, V>(key, value));
        this->deleted[pos] = false;
        this->count++;
        return;
      }
    }
  }
  

  virtual int size() override
  {
    return this->count;
  }
  
  virtual bool contains(K key) override {
    int hash1 = hashFunc1.hash(key) % this->bucketsSize;
    int hash2 = hashFunc2.hash2(key) % this->bucketsSize;

    for(int i = 0; i < this->bucketsSize; i++){
      int pos = abs((hash1 + i * hash2) % this->bucketsSize);

      if(this->buckets[pos] != nullptr && this->buckets[pos]->get(0).fst == key) {
          return true;
      }
    }
    return false;
 }

  
 virtual void remove(K key) override {
    int hash1 = hashFunc1.hash(key) % this->bucketsSize;
    int hash2 = hashFunc2.hash2(key) % this->bucketsSize;

    for (int i = 0; i < this->bucketsSize; i++)
    {
      int pos = abs((hash1 + i * hash2) % this->bucketsSize);

      if (this->buckets[pos] != nullptr && this->buckets[pos]->get(0).fst == key)
      {
        this->deleted[pos] = true;
        this->count--;
        return;
      }
    }
 }
  
  virtual int capacity() override
  {
    return this->bucketsSize;
  }

};