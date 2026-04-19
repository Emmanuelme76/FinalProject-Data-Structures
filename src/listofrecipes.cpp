// Implementación de List::toStringWithIngredients
#include "listofrecipes.hpp"

// Imprime cada receta usando toString(true)
template <class T, int ARRAYSIZE>
std::string List<T, ARRAYSIZE>::toStringWithIngredients() const {
    std::string result;
    int i = 0;
    while (i <= this->last) {
        result += this->data[i]->toString(true) + "\n";
        i++;
    }
    return result;
}

// Fuerza la instanciación para Recipe
#include "recipe.hpp"
template std::string List<Recipe, 1024>::toStringWithIngredients() const;
