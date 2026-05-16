#include "time.hpp"

using namespace std;

Time::Time() {}

Time::Time(const Time& t) : hours(t.hours), minutes(t.minutes) {}

Time::Time(const int& h, const int& m) : hours(h), minutes(m) {}

Time::~Time() {}

int Time::getHours() const {
  return this->hours;
}

int Time::getMinutes() const {
  return this->minutes;
}

string Time::toString() const {
  char myTime[7];

  sprintf(myTime, "%02i:%02i", this->hours, this->minutes);

  return myTime;
}

int Time::toInt() const {
  return this->hours * 100 + this->minutes;
}

void Time::setHours(const int& h) {
  this->hours = h;
}

void Time::setMinutes(const int& m) {
  this->minutes = m;
}

Time& Time::operator=(const Time& t) {
  this->hours = t.hours;
  this->minutes = t.minutes;
  return *this;
}

bool Time::operator==(const Time& t) const {
  return this->toInt() == t.toInt();
}

bool Time::operator!=(const Time& t) const {
  return !(*this == t);
}

bool Time::operator<(const Time& t) const {
  return this->toInt() < t.toInt();
}

bool Time::operator<=(const Time& t) const {
  return (*this < t or *this == t);
}

bool Time::operator>(const Time& t) const {
  return !(*this <= t);
}

bool Time::operator>=(const Time& t) const {
  return !(*this < t);
}

int Time::compareTo(const Time& t) const {
  return this->toInt() - t.toInt();
}

int Time::compare(const Time& a, const Time& b) {
  return a.toInt() - b.toInt();
}

/**********************************************************/
// Pendiente

string Time::serialize() const {
  return this->toString();
}

void Time::deserialize(const string& str) {  // HH:MM
  stringstream mySStr(str);
  string myStr;

  getline(mySStr, myStr, ':');
  this->hours = stoi(myStr);

  getline(mySStr, myStr, '*');
  this->minutes = stoi(myStr);
}

istream& operator>>(istream& is, Time& t) {
  string myStr;

  getline(is >> std::ws, myStr);
  t.hours = stoi(myStr);
  getline(is >> std::ws, myStr);
  t.minutes = stoi(myStr);

  return is;
}

ostream& operator<<(ostream& os, const Time& t) {
  os << t.hours << "\n";
  os << t.minutes;

  return os;
}
