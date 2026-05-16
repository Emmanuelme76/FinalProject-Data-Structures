#ifndef __INGREDIENT_HPP__
#define __INGREDIENT_HPP__

#include <iostream>
#include <sstream>
#include <string>

class Ingredient {
 private:
  std::string name;
  std::string amount;  // cantidad

 public:
  Ingredient();
  Ingredient(const Ingredient&);
  Ingredient(const std::string&, const std::string&);

  ~Ingredient();

  std::string getName() const;
  std::string getAmount() const;

  std::string toString() const;

  void setName(const std::string&);
  void setAmount(const std::string&);

  Ingredient& operator=(const Ingredient&);

  bool operator==(const Ingredient&) const;
  bool operator!=(const Ingredient&) const;
  bool operator<(const Ingredient&) const;
  bool operator<=(const Ingredient&) const;
  bool operator>(const Ingredient&) const;
  bool operator>=(const Ingredient&) const;

  int compareTo(const Ingredient&) const;
  static int compare(const Ingredient&, const Ingredient&);
  static int compareByName(const Ingredient&, const Ingredient&);

  friend std::ostream& operator<<(std::ostream&, const Ingredient&);
  friend std::istream& operator>>(std::istream&, Ingredient&);

  std::string serialize() const;
  void deserialize(const std::string&);
};

#endif  // __INGREDIENT_HPP__