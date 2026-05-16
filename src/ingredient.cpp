#include "ingredient.hpp"

using namespace std;

Ingredient::Ingredient() {}

Ingredient::Ingredient(const Ingredient& i) : name(i.name), amount(i.amount) {}

Ingredient::Ingredient(const string& n, const string& a) : name(n), amount(a) {}

Ingredient::~Ingredient() {}

string Ingredient::getName() const {
  return this->name;
}

string Ingredient::getAmount() const {
  return this->amount;
}

string Ingredient::toString() const {
  string result;

  string myStr = this->name;
  myStr.resize(30, ' ');
  result += myStr + " | ";

  result += this->amount;

  return result;
}

void Ingredient::setName(const string& n) {
  this->name = n;
}

void Ingredient::setAmount(const string& a) {
  this->amount = a;
}

Ingredient& Ingredient::operator=(const Ingredient& i) {
  this->name = i.name;
  this->amount = i.amount;

  return *this;
}

bool Ingredient::operator==(const Ingredient& i) const {
  return (this->name == i.name);
}

bool Ingredient::operator!=(const Ingredient& i) const {
  return !(*this == i);
}

bool Ingredient::operator<(const Ingredient& i) const {
  return (this->name < i.name);
}

bool Ingredient::operator<=(const Ingredient& i) const {
  return (*this < i or *this == i);
}

bool Ingredient::operator>(const Ingredient& i) const {
  return !(*this <= i);
}

bool Ingredient::operator>=(const Ingredient& i) const {
  return !(*this < i);
}

int Ingredient::compareTo(const Ingredient& other) const {
  return this->name.compare(other.name);
}

int Ingredient::compare(const Ingredient& a, const Ingredient& b) {
  return a.name.compare(b.name);
}

int Ingredient::compareByName(const Ingredient& a, const Ingredient& b) {
  return a.name.compare(b.name);
}

string Ingredient::serialize() const {
  string result;

  result += this->name + '*';
  result += this->amount;

  return result;
}

void Ingredient::deserialize(const string& str) {
  stringstream mySStr(str);
  string myStr;

  getline(mySStr, this->name, '*');
  getline(mySStr, this->amount, '*');
}

istream& operator>>(istream& is, Ingredient& i) {
  string myStr;

  getline(is, i.name);
  getline(is, i.amount);

  return is;
}

ostream& operator<<(ostream& os, const Ingredient& i) {
  os << i.name << '\n';
  os << i.amount;

  return os;
}
