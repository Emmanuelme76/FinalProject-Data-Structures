#ifndef __DLLIST_HPP__
#define __DLLIST_HPP__

#include <exception>
#include <functional>
#include <iostream>
#include <string>

// Definicion

using namespace std;

template <class T>
class DLList {
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
    T* dataPtr = nullptr; 
    Position prev = nullptr;
    Position next = nullptr;

  public:
    class Exception : public DLList<T>::Exception {

    public:
      using DLList<T>::Exception::Exception;
    };

   public:
    Node();
    Node(const T& e);

    T* getDataPtr();
    T& getData();
    Position getPrev();
    Position getNext();

    void setDataPtr(T*);
    void setData(const T&);
    void setPrev(const Position&);
    void setNext(const Position&);
  };

  Position header = new(nothrow) Node;

  bool isValidPos(const Position&) const;

  void addData(const DLList<T>&);

 public:
  DLList();

  DLList(const DLList<T>&);

  ~DLList();

  bool isEmpty() const;

  void insData(const Position&, const T&);  // pos, dato

  void delData(const Position&);  // pos

  Position getFirstPos() const;

  Position getLastPos() const;

  Position getPrevpos(const Position&) const;  // pos

  Position getNextPos(const Position&) const;  // pos

  Position findData(const T&) const;  // dato

  T& retrieve(const Position&);

  string toString() const;

  void delAll();

  DLList<T>& operator=(const DLList<T>&);

  template <class X, int Z>
  friend ostream& operator<<(ostream&, const DLList<X>&);

  template <class X, int Z>
  friend istream& operator>>(istream&, DLList<X>&);

  // Explicitas

  Position findData(const T&, const function<int(const T&, const T&)>&) const;
};

// Implementacion

// Node

template <class T>
DLList<T>::Node::Node() {}

template <class T>
DLList<T>::Node::Node(const T& e) : dataPtr(new(nothrow) T(e)) {
  if(this->dataPtr == nullptr) {
    throw Exception("Memoria no disponible, Node");
  }
}

template <class T>
T* DLList<T>::Node::getDataPtr() {
  return this->dataPtr;
}

template <class T>
T& DLList<T>::Node::getData() {
  if(this->dataPtr == nullptr) {
    throw Exception("Dato inexistente, getData");
  }

  return *this->dataPtr;
}

template <class T>
typename DLList<T>::Position DLList<T>::Node::getPrev() {
  return this->prev;
}

template <class T>
typename DLList<T>::Position DLList<T>::Node::getNext() {
  return this->next;
}

template <class T>
void DLList<T>::Node::setDataPtr(T* p) {
  this->dataPtr = p;
}

template <class T>
void DLList<T>::Node::setData(const T& e) {
  if(this->dataPtr == nullptr) {
    if ((this->dataPtr = new(nothrow) T(e)) == nullptr)
         throw Exception("Memoria mo disponible, setData"); 
  }
  else{
    *this->data = e;
  }
}

template <class T>
void DLList<T>::Node::setPrev(const Position& p) {
  this->prev = p;
}

template <class T>
void DLList<T>::Node::setNext(const Position& p) {
  this->next = p;
}

// DLList
template <class T>
bool DLList<T>::isValidPos(const Position& p) const {
  
  if(p == nullptr || p == this->header) {
    return false;
  }
  
  Position aux(this->header->getNext());

  while (aux != this->header) {
    if (aux == p) {
      return true;
    }

    aux = aux->getNext();
  }

  return false;
}

template <class T>
void DLList<T>::addData(const DLList<T>& other) {
  /*
  Position aux(other.anchor), last(this->getLastPos()), newNode;

  while (aux != nullptr) {
    if ((newNode = new (nothrow) Node(aux->getData())) == nullptr) {
      throw Exception("Memoria no disponible, addData");
    }

    if (last == nullptr) {
      this->anchor = newNode;
    } else {
      newNode->setPrev(last);

      last->setNext(newNode);
    }

    last = newNode;

    aux = aux->getNext();
  }*/

  Position aux(other.header->getNext()), last(this->header->getPrev()), newNode;

  while (aux != other.header) {
    if ((newNode = new (nothrow) Node(aux->getData())) == nullptr) {
      throw Exception("Memoria no disponible, addData");
    }

    newNode->setNext(this->header);
    newNode->setPrev(last);

    last->setNext(newNode);
    this->header->setPrev(newNode);

    last = newNode;

    aux = aux->getNext();
  
  }

}

template <class T>
DLList<T>::DLList() {
  if(this->header == nullptr) {
    throw Exception("Memoria no disponible, DLList");
  }

  this->header->setPrev(this->header);
  this->header->setNext(this->header);
}

template <class T>
DLList<T>::DLList(const DLList<T>& other) : DLList() {
  this->addData(other);
}

template <class T>
DLList<T>::~DLList() {
  this->delAll();

  delete this->header;
}

template <class T>
bool DLList<T>::isEmpty() const {
  return this->header->getNext() == this->header;
}

template <class T>
void DLList<T>::insData(const Position& p, const T& e) {
  if (p != nullptr and !this->isValidPos(p)) {
    throw Exception("Posicion Invalida, insData");
  }

  Position newNode;

  try{
    if ((newNode = new (nothrow) Node(e)) == nullptr) {
    throw Exception("Memoria no disponible, insData");
    }
  } catch(const typename Node::Exception& ex) {
    throw Exception(ex.what());
  }


 Position insPos(p == nullptr ? this->header : p);

 newNode->setPrev(insPos);
 newNode->setNext(insPos->getNext());

 insPos->getNext()->setPrev(newNode);
 insPos->setNext(newNode);
}

template <class T>
void DLList<T>::delData(const Position& p) {
  if (!this->isValidPos(p)) {
    throw Exception("Posicion invalida, delData");
  }

  p->getPrev()->setNext(p->getNext());
  p->getNext()->setPrev(p->getPrev());

  delete p;
}

template <class T>
typename DLList<T>::Position DLList<T>::getFirstPos() const {
  return this->isEmpty() ? nullptr : this->header->getNext();
}

template <class T>
typename DLList<T>::Position DLList<T>::getLastPos() const {
 return this->isEmpty() ? nullptr : this->header->getPrev();
}

template <class T>
typename DLList<T>::Position DLList<T>::getPrevpos(const Position& p) const {
  return (p->getPrev() == this->header or !this->isValidPos(p)) ? nullptr : p->getPrev();
}

template <class T>
typename DLList<T>::Position DLList<T>::getNextPos(const Position& p) const {
  return (p->getNext() == this->header or !this->isValidPos(p)) ? nullptr : p->getNext();
}

template <class T>
typename DLList<T>::Position DLList<T>::findData(const T& e) const {
  Position aux(this->header->getNext());

  while (aux != header) { 
    if (aux->getData() == e) {
      return aux;
    }

      aux = aux->getNext();
    
  }

  return nullptr;
}

template <class T>
typename DLList<T>::Position DLList<T>::findData(const T& e, const function<int(const T&, const T&)>& cmp) const {
  Position aux(this->header->getNext());

  while (aux != header) { 
    if (cmp(aux->getData(), e) == 0) {
      return aux;
    }

      aux = aux->getNext();
    
  }

  return nullptr;
}

template <class T>
T& DLList<T>::retrieve(const Position& p) {
  if (!this->isValidPos(p)) {
    throw Exception("Posicion invalida, retrieve");
  }

  return p->getData();
}

template <class T>
string DLList<T>::toString() const {
  string result;
  Position aux(this->header->getNext());

  while (aux != this->header) {
    result += aux->getData().toString() + "\n";

    aux = aux->getNext();
  }

  return result;
}

template <class T>
void DLList<T>::delAll() {
  Position aux;

  while (this->header->getNext() != this->header) {
    aux = this->header->getNext();

    header->setNext(aux->getNext());

    delete aux;
  }

  this->header->setPrev(this->header);
}

template <class T>
DLList<T>& DLList<T>::operator=(const DLList<T>& other) {
  this->delAll();

  this->addData(other);

  return *this;
}

template <class X>
ostream& operator<<(ostream&, const DLList<X>&) {
  // Pendiente
}

template <class X>
istream& operator>>(istream&, DLList<X>&) {
  // Pendiente
}

#endif  // __DLLIST_HPP__

//Comprender el try catch de 250