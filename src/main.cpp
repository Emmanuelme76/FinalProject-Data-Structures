#include "dllist.hpp"
#include "recipeinterface.hpp"

int main() {
  new RecipeInterface(*new DLList<Recipe>);
}
