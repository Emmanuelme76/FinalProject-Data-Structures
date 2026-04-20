#ifndef __LIST_HPP__
#define __LIST_HPP__

#include <exception>
#include <functional>
#include <iostream>
#include <string>

// Definicion

using namespace std;

template <class T, int ARRAYSIZE = 1024>  // De esta manera se puede dejar un
                                          // tamaño por defecto
                                          class List {
 private:
  T data[ARRAYSIZE];
  int last = -1;

  bool isValid(const int&) const;

  void copyAll(const List<T, ARRAYSIZE>&);

  void swapData(T&, T&);

  void sortDataMerge(const int&, const int&);
  void sortDataMerge(const int&,
                     const int&,
                     const function<int(const T&, const T&)>&);

  void sortDataQuick(const int&, const int&);
  void sortDataQuick(const int&,
                     const int&,
                     const function<int(const T&, const T&)>&);

 public:
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
  List();
  List(const List<T, ARRAYSIZE>&);

  bool isEmpty() const;

  bool isFull() const;

  bool isSorted() const;

  void instData(const int&, const T&);  // pos, dato

  void insertSortedData(const T&);

  void delData(const int&);  // pos

  int getFirstPos() const;

  int getLastPos() const;

  int getPrevpos(const int&) const;  // pos

  int getNextPos(const int&) const;  // pos

  int findData(const T&) const;  // dato

  int findDataL(const T&) const;
  int findDataB(const T&) const;

  void sortData();

  void sortDataBubble();
  void sortDataInsert();
  void sortDataSelect();
  void sortDataShell();
  void sortDataMerge();
  void sortDataQuick();

  T& retreive(const int&);

  std::string toString() const;

  std::string toStringWithIngredients() const;

  void delAll();

  List<T, ARRAYSIZE>& operator=(const List<T, ARRAYSIZE>&);

  template <class X, int Z>
  friend ostream& operator<<(ostream&, const List<X, Z>&);

  template <class X, int Z>
  friend istream& operator>>(istream&, List<X, Z>&);

  // Explicitas

  bool isSorted(const function<int(const T&, const T&)>&) const;

  int findDataL(const T&, int(const T&, const T&)) const;
  int findDataB(const T&, int(const T&, const T&)) const;

  void sortDataBubble(const function<int(const T&, const T&)>&);
  void sortDataInsert(const function<int(const T&, const T&)>&);
  void sortDataSelect(const function<int(const T&, const T&)>&);
  void sortDataShell(const function<int(const T&, const T&)>&);

  void sortDataMerge(const function<int(const T&, const T&)>&);
  void sortDataQuick(const function<int(const T&, const T&)>&);
};

// Implementacion

template <class T, int ARRAYSIZE>
bool List<T, ARRAYSIZE>::isValid(const int& p) const {
  return p >= 0 and p <= this->last;  // el ultimo es el last (el contador)
}

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::copyAll(const List<T, ARRAYSIZE>& other) {
  int i(0);

  while (i <= other.last) {
    this->data[i] = other.data[i];

    i++;
  }

  this->last = other.last;
}
template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::swapData(T& a, T& b) {
  T aux(a);
  a = b;
  b = aux;
}

template <class T, int ARRAYSIZE>
List<T, ARRAYSIZE>::List() {}

template <class T, int ARRAYSIZE>
List<T, ARRAYSIZE>::List(const List<T, ARRAYSIZE>& other) {
  this->copyAll(other);
}

template <class T, int ARRAYSIZE>
bool List<T, ARRAYSIZE>::isEmpty() const {
  return this->last == -1;
}

template <class T, int ARRAYSIZE>
bool List<T, ARRAYSIZE>::isFull() const {
  return this->last == ARRAYSIZE - 1;
}

template <class T, int ARRAYSIZE>
bool List<T, ARRAYSIZE>::isSorted() const {
  int i(0);

  while (i < this->last) {
    if (this->data[i] > this->data[i + 1]) {
      return false;
    }

    i++;
  }

  return true;
}

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::instData(const int& p, const T& e) {
  if (this->isFull()) {
    throw Exception("Desbordamiento de datos, insData");
  }

  if (p != -1 and !this->isValid(p)) {
    throw Exception("Posicion Invalida, insData");
  }

  int i(this->last);

  while (i > p) {
    this->data[i] = this->data[i + 1];

    i--;
  }

  this->data[p + 1] = e;

  this->last++;
}

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::insertSortedData(const T& e) {
  if (this->isFull()) {
    throw Exception("Desbordamiento de datos, insertSortedData");
  }

  if(this->isEmpty()) {
    this->data[0] = e;
    this->last ++;

    return;
  }

  int i(this->getLastPos());
  
  while(i != -1 && data[i] > e) {
  this->data[i + 1] = this->data[i];
    i--;
  }

  this->data[i + 1] = e;

  this->last ++;
}


template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::delData(const int& p) {
  if (!this->isValid(p)) {
    throw Exception("Posición Invalida, delData");
  }

  int i(p);

  while (i < this->last) {
    this->data[i] = this->data[i + 1];

    i++;
  }

  this->last--;
}

template <class T, int ARRAYSIZE>
int List<T, ARRAYSIZE>::getFirstPos() const {
  return this->isEmpty() ? -1 : 0;
}

template <class T, int ARRAYSIZE>
int List<T, ARRAYSIZE>::getLastPos() const {
  return this->last;
}

template <class T, int ARRAYSIZE>
int List<T, ARRAYSIZE>::getPrevpos(const int& p) const {
  return (p == 0 or !this->isValid(p)) ? -1 : (p - 1);
}
template <class T, int ARRAYSIZE>
int List<T, ARRAYSIZE>::getNextPos(const int& p) const {
  return p == this->last or !this->isValid(p) ? -1 : (p + 1);
}

template <class T, int ARRAYSIZE>
int List<T, ARRAYSIZE>::findData(const T&) const {
  // Pendiente
}

template <class T, int ARRAYSIZE>
int List<T, ARRAYSIZE>::findDataL(const T& e) const {  // Busqueda lineal
  int i(0);

  while (i <= this->last) {
    if (e == this->data[i]) {
      return i;
    }

    i++;
  }

  return -1;
}

template <class T, int ARRAYSIZE>
int List<T, ARRAYSIZE>::findDataB(const T& e) const {  // Busqueda Binaria
  int i(0), j(this->last), m;

  while (i <= j) {
    m = (i + j) / 2;

    if (e == this->data[m]) {
      return m;
    }

    if (e < this->data[m]) {
      j = m - 1;
    } else {
      i = m + 1;
    }
  }

  return -1;
}

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::sortData() {
  // Pendiente
}

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::sortDataBubble() {
  int i(this->last), j;
  bool flag;

  do {
    flag = false;

    j = 0;

    while (j < i) {
      if (this->data[j] > this->data[j + 1]) {
        this->swapData(this->data[j], this->data[j + 1]);

        flag = true;
      }

      j++;
    }

    i--;

  } while (flag);
}

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::sortDataInsert() {
  int i(1), j;
  T aux;

  while (i <= this->last) {
    aux = this->data[i];

    j = i;

    while (j > 0 and aux < this->data[j - 1]) {
      this->data[j] = this->data[j - 1];

      j--;
    }

    if (i != j) {
      this->data[j] = aux;
    }

    i++;
  }
}

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::sortDataSelect() {
  int i(0), j, m;

  while (i < this->last) {
    m = i;

    j = i + 1;

    while (j <= this->last) {
      if (this->data[j] < this->data[m]) {
        m = j;
      }

      j++;
    }

    if (i != j) {
      this->swapData(this->data[i], this->data[m]);
    }

    i++;
  }
}

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::sortDataShell() {
  int series[] = {510774, 227011, 100894, 44842, 19930, 8858, 3937, 1750, 701,
                  301,    132,    57,     23,    10,    4,    1,    0};

  int count(0), dif(series[count]), i, j;

  while (dif > 0) {
    i = dif;

    while (i <= this->last) {
      j = i;

      while (j >= dif and this->data[j - dif] > this->data[j]) {
        this->swapData(this->data[j - dif], this->data[j]);

        j -= dif;
      }

      i++;
    }

    dif = series[++count];
  }
}

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::sortDataMerge() {
  this->sortDataMerge(0, this->last);
}

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::sortDataMerge(const int& leftEdge,
                                       const int& rightEdge) {
  if (leftEdge >= rightEdge) {  // Criterio de Paro
    return;
  }

  // Divide y venceras
  int m((leftEdge + rightEdge) / 2);

  this->sortDataMerge(leftEdge, m);
  this->sortDataMerge(m + 1, rightEdge);

  // Intercalacion
  static T temp[ARRAYSIZE];

  for (int z(leftEdge); z <= rightEdge; temp[z++] = this->data[z])
    ;

  int i(leftEdge), j(m + 1), x(leftEdge);

  while (i <= m and j <= rightEdge) {
    while (i <= m and temp[i] <= temp[j]) {
      this->data[x++] = temp[i++];
    }

    if (i <= m) {
      while (j <= rightEdge and temp[j] <= temp[i]) {
        this->data[x++] = temp[j++];
      }
    }
  }

  while (i <= m) {
    this->data[x++] = temp[i++];
  }

  while (j <= rightEdge) {
    this->data[x++] = temp[j++];
  }
}

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::sortDataQuick() {
  this->sortDataQuick(0, this->last);
}

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::sortDataQuick(const int& leftEdge,
                                       const int& rightEdge) {
  if (leftEdge >= rightEdge) {  // Criterio de paro
    return;
  }

  // Separacion
  int i(leftEdge), j(rightEdge);

  while (i < j) {
    while (i < j and this->data[i] <= this->data[rightEdge]) {
      i++;
    }

    while (i < j and this->data[j] >= this->data[rightEdge]) {
      j--;
    }

    if (i != j) {
      this->swapData(this->data[i], this->data[j]);
    }
  }

  if (i != rightEdge) {
    this->swapData(this->data[i], this->data[rightEdge]);
  }

  // Divide y venceras
  this->sortDataQuick(leftEdge, i - 1);
  this->sortDataQuick(i + 1, rightEdge);
}

template <class T, int ARRAYSIZE>
T& List<T, ARRAYSIZE>::retreive(const int& p) {
  if (!this->isValid(p)) {
    throw Exception("Posicion invalida, retrieve");
  }

  return this->data[p];
}

template <class T, int ARRAYSIZE>
string List<T, ARRAYSIZE>::toString() const {
  string result;

  int i(0);

  while (i <= this->last) {
    result += this->data[i].toString() + "\n";

    i++;
  }

  return result;
}


template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::delAll() {
  this->last = -1;
}
template <class T, int ARRAYSIZE>
List<T, ARRAYSIZE>& List<T, ARRAYSIZE>::operator=(const List& other) {
  this->copyAll(other);

  return *this;
}

template <class X, int Z>
ostream& operator<<(ostream& os, const List<X, Z>& l) {
  int i(0);

  while (i <= l.last) {
    os << l.data[i] << std::endl;

    i++;
  }

  return os;
}

template <class X, int Z>
istream& operator>>(istream& is, List<X, Z>& l) {
  X myObj;

  try {
    while (!is.eof()) {
      is >> myObj;

      l.instData(l.getLastPos(), myObj);
    }
  } catch (const invalid_argument& ex) {
  } catch (const typename List<X, Z>::Exception& ex) {
  }

  return is;
}

// Explicitas

template <class T, int ARRAYSIZE>
bool List<T, ARRAYSIZE>::isSorted(
    const function<int(const T&, const T&)>& cmp) const {
  int i(0);

  while (i < this->last) {
    if (cmp(this->data[i], this->data[i + 1]) > 0) {
      return false;
    }

    i++;
  }

  return true;
}

template <class T, int ARRAYSIZE>
int List<T, ARRAYSIZE>::findDataL(const T& e,
                                  int cmp(const T&, const T&)) const {
  int i(0);

  while (i <= this->last) {
    if (cmp(e, this->data[i]) == 0) {
      return i;
    }

    i++;
  }

  return -1;
}

template <class T, int ARRAYSIZE>
int List<T, ARRAYSIZE>::findDataB(const T& e,
                                  int cmp(const T&, const T&)) const {
  int i(0), j(this->last), m;

  while (i <= j) {
    m = (i + j) / 2;

    if (cmp(e, this->data[m]) == 0) {
      return m;
    }

    if (cmp(e, this->data[m]) < 0) {
      j = m - 1;
    } else {
      i = m + 1;
    }
  }

  return -1;
}

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::sortDataBubble(
    const function<int(const T&, const T&)>& cmp) {
  int i(this->last), j;
  bool flag;

  do {
    flag = false;

    j = 0;

    while (j < i) {
      if (cmp(this->data[j], this->data[j + 1]) > 0) {
        this->swapData(this->data[j], this->data[j + 1]);

        flag = true;
      }

      j++;
    }

    i--;

  } while (flag);
}

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::sortDataInsert(
    const function<int(const T&, const T&)>& cmp) {
  int i(1), j;
  T aux;

  while (i <= this->last) {
    aux = this->data[i];

    j = i;

    while (j > 0 and cmp(aux, this->data[j - 1]) < 0) {
      this->data[j] = this->data[j - 1];

      j--;
    }

    if (i != j) {
      this->data[j] = aux;
    }

    i++;
  }
}

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::sortDataSelect(
    const function<int(const T&, const T&)>& cmp) {
  int i(0), j, m;

  while (i < this->last) {
    m = i;

    j = i + 1;

    while (j <= this->last) {
      if (cmp(this->data[j], this->data[m]) < 0) {
        m = j;
      }

      j++;
    }

    if (i != j) {
      this->swapData(this->data[i], this->data[m]);
    }

    i++;
  }
}

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::sortDataShell(
    const function<int(const T&, const T&)>& cmp) {
  int series[] = {510774, 227011, 100894, 44842, 19930, 8858, 3937, 1750, 701,
                  301,    132,    57,     23,    10,    4,    1,    0};

  int count(0), dif(series[count]), i, j;

  while (dif > 0) {
    i = dif;

    while (i <= this->last) {
      j = i;

      while (j >= dif and cmp(this->data[j - dif], this->data[j]) > 0) {
        this->swapData(this->data[j - dif], this->data[j]);

        j -= dif;
      }

      i++;
    }

    dif = series[++count];
  }
}

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::sortDataMerge(
    const function<int(const T&, const T&)>& cmp) {
  this->sortDataMerge(0, this->last, cmp);
}

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::sortDataMerge(
    const int& leftEdge,
    const int& rightEdge,
    const function<int(const T&, const T&)>& cmp) {
  if (leftEdge >= rightEdge) {  // Criterio de Paro
    return;
  }

  // Divide y venceras
  int m((leftEdge + rightEdge) / 2);

  this->sortDataMerge(leftEdge, m, cmp);
  this->sortDataMerge(m + 1, rightEdge, cmp);

  // Intercalacion
  static T temp[ARRAYSIZE];

  for (int z(leftEdge); z <= rightEdge; temp[z++] = this->data[z])
    ;

  int i(leftEdge), j(m + 1), x(leftEdge);

  while (i <= m and j <= rightEdge) {
    while (i <= m and cmp(temp[i], temp[j]) <= 0) {
      this->data[x++] = temp[i++];
    }

    if (i <= m) {
      while (j <= rightEdge and cmp(temp[j], temp[i]) <= 0) {
        this->data[x++] = temp[j++];
      }
    }
  }

  while (i <= m) {
    this->data[x++] = temp[i++];
  }

  while (j <= rightEdge) {
    this->data[x++] = temp[j++];
  }
}

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::sortDataQuick(
    const function<int(const T&, const T&)>& cmp) {
  this->sortDataQuick(0, this->last, cmp);
}

template <class T, int ARRAYSIZE>
void List<T, ARRAYSIZE>::sortDataQuick(
    const int& leftEdge,
    const int& rightEdge,
    const function<int(const T&, const T&)>& cmp) {
  if (leftEdge >= rightEdge) {  // Criterio de paro
    return;
  }

  // Separacion
  int i(leftEdge), j(rightEdge);

  while (i < j) {
    while (i < j and cmp(this->data[i], this->data[rightEdge]) <= 0) {
      i++;
    }

    while (i < j and cmp(this->data[j], this->data[rightEdge]) >= 0) {
      j--;
    }

    if (i != j) {
      this->swapData(this->data[i], this->data[j]);
    }
  }

  if (i != rightEdge) {
    this->swapData(this->data[i], this->data[rightEdge]);
  }

  // Divide y venceras
  this->sortDataQuick(leftEdge, i - 1, cmp);
  this->sortDataQuick(i + 1, rightEdge, cmp);
}

#endif  // __LIST_HPP__
