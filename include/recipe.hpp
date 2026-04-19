#ifndef __RECIPE_HPP__
#define __RECIPE_HPP__

#include <string>
#include <iostream>

#include "ingredient.hpp"
#include "name.hpp"
#include "time.hpp"
#include "list.hpp"

class Recipe{
private:
    std::string name;
    List<Ingredient> ingredientList;
    Time preparationTime;
    std::string instructions;
    Name author;
    std::string category; //Breakfast, Lunch, Dinner, Christmas.

public:
    Recipe();
    Recipe(const Recipe&);

    ~Recipe();

    std::string getName()const;
    List<Ingredient>& getListIngredient();
    Time getPreparationTime()const;
    std::string getInstructions()const;
    Name getAuthor()const;
    std::string getCategory()const;

    std::string toString(const bool& showIngredients = false)const;
    static std::string toStringWithIngredientList(const Recipe);

    void setName(const std::string&);
    void setIngredientList(const List<Ingredient>&);
    void setPreparationTime(const Time&);
    void setInstructions(const std::string&);
    void setAuthor(const Name&);
    void setCategory(const std::string&);

    Recipe& operator = (const Recipe&);

    bool operator == (const Recipe&)const;
    bool operator != (const Recipe&)const;
    bool operator < (const Recipe&)const;
    bool operator <= (const Recipe&)const;
    bool operator > (const Recipe&)const;
    bool operator >= (const Recipe&)const;

    int compareTo(const Recipe&)const;
    static int compare(const Recipe&, const Recipe&);

    static int compareByName(const Recipe&, const Recipe&);
    static int compareByPreparationTime(const Recipe&, const Recipe&);
    static int compareByInstructions(const Recipe&, const Recipe&);
    static int compareByAuthor(const Recipe&, const Recipe&);
    static int compareByCategory(const Recipe&, const Recipe&);

    friend std::ostream& operator << (std::ostream&, const Recipe&);
    friend std::istream& operator >> (std::istream&, Recipe&);

    std::string serialize() const;
    void deserialize(const std::string&); 


};
#endif // __RECIPE_HPP__