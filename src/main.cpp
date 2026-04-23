#include "recipeinterface.hpp"
#include "dllist.hpp"

int main() {
    new RecipeInterface(*new DLList<Recipe>);
}
