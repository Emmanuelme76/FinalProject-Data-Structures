#ifndef __INGREDIENTINTERFACE_HPP__
#define __INGREDIENTINTERFACE_HPP__

#include <string>
#include <fstream>
#include <iostream>

#include "listofingredients.hpp"
#include "ingredient.hpp"

class IngredientInterface{
private:
    List<Ingredient>* myListRef;

    void mainMenu();

    void addIngredient();

    void delIngredient();

    void delAllIngredients();

    void editIngredient();

    void showList();

    void enterToContinue();

public:
    IngredientInterface(List<Ingredient>&);

};

#endif // __INGREDIENTINTERFACE_HPP__