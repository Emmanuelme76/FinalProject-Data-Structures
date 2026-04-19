#ifndef __RECIPEINTERFACE_HPP__
#define __RECIPEINTERFACE_HPP__

#include <string>
#include <fstream>
#include <iostream>

#include "list.hpp"
#include "recipe.hpp"



class RecipeInterface{
private:
    List<Recipe>* myListRef;

    void menu();
    
    void mainMenu();
    
    void addRecipe();
    
    void delRecipe();

    void delAllRecipes();
    
    void editRecipe();
    
    void showList();

    void sortData();
    
    void writeToDisk();
    
    void readFromDisk();
    
    void enterToContinue();
    
    public:
    RecipeInterface(List<Recipe>&);
};

#endif // __RECIPEINTERFACE_HPP__