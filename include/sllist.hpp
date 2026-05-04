#ifndef __SLLIST_HPP__
#define __SLLIST_HPP__

#include <exception>
#include <functional>
#include <iostream>
#include <string>
#include <sstream>

// Definicion

using namespace std;

template <class T>
class SLList {
  class Node;

 public:
  typedef Node* Position;

  class Exception : public exception {
   private:
    string msg;

   public:
    Exception() noexcept : msg("Error Indefinido") {}
    Exception(const Exception& ex) noexcept : msg(ex.msg) {}
    Exception(const string& m) : msg(m) {}
    Exception& operator=(const Exception& ex) noexcept {
      msg = ex.msg;

      return *this;
    }
    virtual ~Exception() {}
    virtual const char* what() const noexcept { return msg.c_str(); }
  };

 private:
  class Node {
   private:
    T data;
    Position next = nullptr;

   public:
    Node();
    Node(const T& e);

    T& getData();
    Position getNext();

    void setData(const T&);
    void setNext(const Position&);
  };

  Position anchor = nullptr;

  bool isValidPos(const Position&) const;

  void addData(const SLList<T>&);

 public:
  SLList();

  SLList(const SLList<T>&);

  ~SLList();

  bool isEmpty() const;

  void insData(const Position&, const T&);  // pos, dato

  void insertSortedData(const T&);

  void delData(const Position&);  // pos

  Position getFirstPos() const;

  Position getLastPos() const;

  Position getPrevpos(const Position&) const;  // pos

  Position getNextPos(const Position&) const;  // pos

  Position findData(const T&) const;  // dato

  T& retrieve(const Position&);

  string toString() const;

  void delAll();

  SLList<T>& operator=(const SLList<T>&);

  std::string serialize(const char& delim = '#') const;

  void deserialize(const std::string&, const char& delim = '#');

  template <class X, int Z>
  friend ostream& operator<<(ostream&, const SLList<X>&);

  template <class X, int Z>
  friend istream& operator>>(istream&, SLList<X>&);

  // Explicitas

  Position findData(const T&, const function<int(const T&, const T&)>&) const;
};

// Implementacion

// Node

template <class T>
SLList<T>::Node::Node() {}

template <class T>
SLList<T>::Node::Node(const T& e) : data(e) {}

template <class T>
T& SLList<T>::Node::getData() {
  return this->data;
}

template <class T>
typename SLList<T>::Position SLList<T>::Node::getNext() {
  return this->next;
}

template <class T>
void SLList<T>::Node::setData(const T& e) {
  this->data = e;
}

template <class T>
void SLList<T>::Node::setNext(const Position& p) {
  this->next = p;
}

// SLList
template <class T>
bool SLList<T>::isValidPos(const Position& p) const {
  Position aux(this->anchor);

  while (aux != nullptr) {
    if (aux == p) {
      return true;
    }

    aux = aux->getNext();
  }

  return false;
}

template <class T>
void SLList<T>::addData(const SLList<T>& other) {
  Position aux(other.anchor), last(this->getLastPos()), newNode;

  while (aux != nullptr) {
    if ((newNode = new (nothrow) Node(aux->getData())) == nullptr) {
      throw Exception("Memoria no disponible, addData");
    }

    if (last == nullptr) {
      this->anchor = newNode;
    } else {
      last->setNext(newNode);
    }

    last = newNode;

    aux = aux->getNext();
  }
}

template <class T>
SLList<T>::SLList() {}

template <class T>
SLList<T>::SLList(const SLList<T>& other) {
  this->addData(other);
}

template <class T>
SLList<T>::~SLList() {
  this->delAll();
}

template <class T>
bool SLList<T>::isEmpty() const {
  return this->anchor == nullptr;
}

template <class T>
void SLList<T>::insData(const Position& p, const T& e) {
  if (p != nullptr and !this->isValidPos(p)) {
    throw Exception("Posicion Invalida, insData");
  }

  Position newNode(new (nothrow) Node(e));

  if (newNode == nullptr) {
    throw Exception("Memoria no disponible, insData");
  }

  if (p == nullptr) {  // al principio
    newNode->setNext(this->anchor);

    this->anchor = newNode;
  } else {
    newNode->setNext(p->getNext());

    p->setNext(newNode);
  }
}

template <class T>
void SLList<T>::insertSortedData(const T& e) {
  Position newNode(new(nothrow) Node(e));
  
  if (newNode == nullptr) {
    throw Exception("Memoria no disponible, insertSortedData");
  }

  if(this->isEmpty() || e < this->anchor->getData()) {
    newNode->setNext(this->anchor);
    this->anchor = newNode;

  }
  else{
    Position aux(this->anchor);

    while (aux->getNext() != nullptr && aux->getNext()->getData() < e) {
            aux = aux->getNext();
        }

        newNode->setNext(aux->getNext());
        
        aux->setNext(newNode);

  }

}

template <class T>
void SLList<T>::delData(const Position& p) {
  if (!this->isValidPos(p)) {
    throw Exception("Posicion invalida, delData");
  }

  if (p == this->anchor) {  // El primero
    this->anchor = p->getNext();
  } else {
    this->getPrevpos(p)->setNext(p->getNext());
  }

  delete p;
}

template <class T>
typename SLList<T>::Position SLList<T>::getFirstPos() const {
  return this->anchor;
}

template <class T>
typename SLList<T>::Position SLList<T>::getLastPos() const {
  if (this->isEmpty()) {
    return nullptr;
  }

  Position aux(this->anchor);
  while (aux->getNext() != nullptr) {
    aux = aux->getNext();
  }

  return aux;
}

template <class T>
typename SLList<T>::Position SLList<T>::getPrevpos(const Position& p) const {
  Position aux(this->anchor);

  while (aux != nullptr and aux->getNext() != p) {
    aux = aux->getNext();
  }

  return aux;
}

template <class T>
typename SLList<T>::Position SLList<T>::getNextPos(const Position& p) const {
  if (!this->isValidPos(p)) {
    return nullptr;
  }

  return p->getNext();
}

template <class T>
typename SLList<T>::Position SLList<T>::findData(const T& e) const {
  Position aux(this->anchor);

  while (aux != nullptr and aux->getData() != e) {
    aux = aux->getNext();
  }

  return aux;
}

template <class T>
typename SLList<T>::Position SLList<T>::findData(
    const T& e,
    const function<int(const T&, const T&)>& cmp) const {
  Position aux(this->anchor);

  while (aux != nullptr and cmp(aux->getData(), e) != 0) {
    aux = aux->getNext();
  }

  return aux;
}

template <class T>
T& SLList<T>::retrieve(const Position& p) {
  if (!this->isValidPos(p)) {
    throw Exception("Posicion invalida, retrieve");
  }

  return p->getData();
}

template <class T>
string SLList<T>::toString() const {
  string result;
  Position aux(this->anchor);

  while (aux != nullptr) {
    result += aux->getData().toString() + "\n";

    aux = aux->getNext();
  }

  return result;
}

template <class T>
void SLList<T>::delAll() {
  Position aux;

  while (this->anchor != nullptr) {
    aux = this->anchor;

    anchor = anchor->getNext();

    delete aux;
  }
}

template <class T>
SLList<T>& SLList<T>::operator=(const SLList<T>& other) {
  this->delAll();

  this->addData(other);

  return *this;
}

template <class T>
std::string SLList<T>::serialize(const char& delim) const {
  std::string result;
  Position aux(this->anchor);

  while(aux != nullptr) {
    result+= aux->getData().serialize() + delim;

    aux = aux->getNext();
  }

  return result;
}

template <class T>
void SLList<T>::deserialize(const std::string& str, const char& delim)  {
  std::stringstream mySStr(str);
  std::string myStr;
  T myObj;

  this->delAll();

  while(!mySStr.eof()) {
    getline(mySStr, myStr, delim);

    if(!myStr.empty()) {
      myObj.deserialize(myStr);

      this->insData(this->getLastPos(), myObj);
    }

  }

}
/*
template <class X>
ostream& operator<<(ostream&, const SLList<X>&) {
  // Pendiente
}

template <class X>
istream& operator>>(istream&, SLList<X>&) {
  // Pendiente
}*/

#endif  // __SLLIST_HPP__
