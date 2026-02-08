#pragma once
#include <string>
#include "./pair.cpp"
#include "./linked_list.cpp"
#include "./map.cpp"


template <class K, class V>
class OpenHashMap : public Map<K, V>
{
private:
  // List<Pair<K,V>>*[] arr
  List<Pair<K, V>> **buckets;
  int bucketsSize;
  int count = 0;

  int abs(int x)
  {
    if (x < 0)
    {
      return -x;
    }
    return x;
  }

public:

    int hash(std::string key) {
        int h = 0;
        for (char c : key) {
            h = 31 * h + int(c);
        }
        return h;
    }

  OpenHashMap(int expectedSize)
  {
    // con un factor de carga de ~1.5
    this->bucketsSize = expectedSize * 2 / 3;
    this->buckets = new List<Pair<K, V>> *[this->bucketsSize];
  }

  virtual V get(K key) override {
    int pos = abs(hash(key) % this->bucketsSize);
    if (this->buckets[pos] != nullptr) {
        for (int i = 0; i < this->buckets[pos]->size(); i++) {
            Pair<K, V> p = this->buckets[pos]->get(i);
            if (p.fst == key) {
                return p.snd;
            }
        }
    }
    throw "Clave no encontrada";
 }

  virtual void set(K key, V value) override
  {
    //this->remove(key);

    int pos = abs(hash(key) % this->bucketsSize);

    if (this->buckets[pos] == nullptr)
    {
      this->buckets[pos] = new LinkedList<Pair<K, V>>();
    }

    this->buckets[pos]->add(Pair<K, V>(key, value));
    this->count++;
  }

  virtual int size() override
  {
    return this->count;
  }
  
  virtual bool contains(K key) override {
    int pos = abs(hash(key) % this->bucketsSize);
    if (this->buckets[pos] != nullptr) {
        for (int i = 0; i < this->buckets[pos]->size(); i++) {
            if (this->buckets[pos]->get(i).fst == key) {
                return true;
            }
        }
    }
    return false;
 }

  
 virtual void remove(K key) override {
  int pos = abs(hash(key) % this->bucketsSize);
  if (this->buckets[pos] != nullptr) {
      for (int i = 0; i < this->buckets[pos]->size(); i++) {
          if (this->buckets[pos]->get(i).fst == key) {
              this->buckets[pos]->remove(this->buckets[pos]->get(i));
              this->count--;
              break;
          }
      }
  }
}
  
  virtual int capacity() override
  {
    return this->bucketsSize;
  }

};