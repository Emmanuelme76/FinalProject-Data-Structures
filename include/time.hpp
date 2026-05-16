#ifndef __TIME_HPP__
#define __TIME_HPP__

#include <iostream>
#include <sstream>
#include <string>

class Time {
 private:
  int hours;
  int minutes;

 public:
  Time();
  Time(const Time&);
  Time(const int&, const int&);

  ~Time();

  int getHours() const;
  int getMinutes() const;

  std::string toString() const;
  int toInt() const;

  void setHours(const int&);
  void setMinutes(const int&);

  Time& operator=(const Time&);

  bool operator==(const Time&) const;
  bool operator!=(const Time&) const;
  bool operator<(const Time&) const;
  bool operator<=(const Time&) const;
  bool operator>(const Time&) const;
  bool operator>=(const Time&) const;

  int compareTo(const Time&) const;
  static int compare(const Time&, const Time&);

  friend std::ostream& operator<<(std::ostream&, const Time&);
  friend std::istream& operator>>(std::istream&, Time&);

  std::string serialize() const;
  void deserialize(const std::string&);
};

#endif  // __TIME_HPP__