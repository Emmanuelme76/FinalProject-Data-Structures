#ifndef __INGREDIENTINTERFACE_HPP__
#define __INGREDIENTINTERFACE_HPP__

#include <fstream>
#include <iostream>
#include <string>

#include "ingredient.hpp"
#include "sllist.hpp"

class IngredientInterface {
 private:
  SLList<Ingredient>* myListRef;

 public:
  void mainMenu();

  void addIngredient();

  void delIngredient();

  void delAllIngredients();

  void editIngredient();

  void showList();

  void enterToContinue();

 public:
  IngredientInterface(SLList<Ingredient>&);
};

#endif  // __INGREDIENTINTERFACE_HPP__