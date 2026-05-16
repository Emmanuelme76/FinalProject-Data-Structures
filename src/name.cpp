#include "name.hpp"

using namespace std;

Name::Name() {}

Name::Name(const Name& n) : last(n.last), first(n.first) {}

Name::Name(const string& l, const string& f) : last(l), first(f) {}

Name::~Name() {}

string Name::getLast() const {
  return this->last;
}

string Name::getFirst() const {
  return this->first;
}

string Name::toString() const {
  return this->last + " " + this->first;
}

void Name::setLast(const string& l) {
  this->last = l;
}

void Name::setFirst(const string& f) {
  this->first = f;
}

Name& Name::operator=(const Name& n) {
  this->last = n.last;
  this->first = n.first;

  return *this;
}

bool Name::operator==(const Name& n) const {
  return this->last == n.last and this->first == n.first;
}

bool Name::operator!=(const Name& n) const {
  return !(*this == n);
}

bool Name::operator<(const Name& n) const {
  return this->last < n.last and this->first < n.first;
}

bool Name::operator<=(const Name& n) const {
  return (*this < n or *this == n);
}

bool Name::operator>(const Name& n) const {
  return !(*this <= n);
}

bool Name::operator>=(const Name& n) const {
  return !(*this < n);
}

int Name::compareTo(const Name& other) const {
  return this->last.compare(other.last);
}

int Name::compare(const Name& a, const Name& b) {
  return a.last.compare(b.last);
}

int Name::compareByLast(const Name& a, const Name& b) {
  return a.last.compare(b.last);
}

int Name::compareByFirst(const Name& a, const Name& b) {
  return a.first.compare(b.first);
}

/**********************************************************/
// Pendiente

string Name::serialize() const {
  return this->last + ',' + this->first;
}

void Name::deserialize(const string& str) {
  stringstream mySStr(str);

  getline(mySStr, this->last, ',');
  getline(mySStr, this->first, '*');
}

istream& operator>>(istream& is, Name& n) {
  string myStr;

  getline(is, n.last);
  getline(is, n.first);

  return is;
}

ostream& operator<<(ostream& os, const Name& n) {
  os << n.last << "\n";
  os << n.first;

  return os;
}
