#pragma once

template <class K, class V>
class Map
{
public:
  virtual V get(K key) = 0;
  virtual void set(K key, V value) = 0;
  virtual int size() = 0;
  virtual bool contains(K key) = 0;
  virtual void remove(K key) = 0;
  // este sirve para debugging
  virtual int capacity() = 0;
};