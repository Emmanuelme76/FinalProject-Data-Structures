#include "recipe.hpp"

using namespace std;

Recipe::Recipe() {}

Recipe::Recipe(const Recipe& r) : name(r.name), ingredientList(r.ingredientList), preparationTime(r.preparationTime), 
                                  instructions(r.instructions), author(r.author)  {}

Recipe::~Recipe() {}

string Recipe::getName() const {
    return this->name;
}

List<Ingredient>& Recipe::getListIngredient() {
    return this->ingredientList;
}

Time Recipe::getPreparationTime() const {
    return this->preparationTime;
}

string Recipe::getInstructions() const {
    return this->instructions;
}

Name Recipe::getAuthor() const {
    return this->author;
}

std::string Recipe::getCategory() const {
    return this->category;
}

string Recipe::toString(const bool& showIngredients) const {
    string result;

    result += "Nombre: " + this->name + "\n";
    result += "Tiempo de preparación: " + this->preparationTime.toString() + "\n";
    
    result += "Instrucciones: " + this->instructions + "\n";
    result += "Autor: " + this->author.toString() + "\n";
    result += "Categoría: " + this->category + "\n";   
    if(showIngredients){
        result += "\n";

        this->ingredientList.toString();

        result += "\n\n";
    }
    return result;
}

string Recipe::toStringWithIngredientList(const Recipe) {}

void Recipe::setName(const string& n) {
    this->name = n;
}

void Recipe::setIngredientList(const List<Ingredient>& l) {
    this->ingredientList = l;
}

void Recipe::setPreparationTime(const Time& p) {
    this->preparationTime = p;
}

void Recipe::setInstructions(const string& i) {
    this->instructions = i;
}

void Recipe::setAuthor(const Name& a) {
    this->author = a;
}

void Recipe::setCategory(const std::string& c) {
    this->category = c;
}

Recipe& Recipe::operator=(const Recipe& r) {
    if(*this == r){
        return *this;
    }
    this->name = r.name;
    this->ingredientList = r.ingredientList;
    this->preparationTime = r.preparationTime;
    this->instructions = r.instructions;
    this->author = r.author;
    
    return *this;
}

bool Recipe::operator==(const Recipe& r) const {
    return this->name == r.name;
}

bool Recipe::operator!=(const Recipe& r) const {
    return !(*this == r);
}

bool Recipe::operator<(const Recipe& r) const {
    return this->name < r.name;
}

bool Recipe::operator<=(const Recipe& r) const {
    return (*this < r or *this == r);
}

bool Recipe::operator>(const Recipe& r) const {
    return !(*this <= r);
}

bool Recipe::operator>=(const Recipe& r) const {
    return !(*this < r);
}

int Recipe::compareTo(const Recipe& other) const {
    return this->name.compare(other.name);
}

int Recipe::compare(const Recipe& a, const Recipe& b) {
    return a.name.compare(b.name);
}

int Recipe::compareByName(const Recipe& a, const Recipe& b) {
    return a.name.compare(b.name);
}

int Recipe::compareByPreparationTime(const Recipe& a, const Recipe& b) {
    return Time::compare(a.preparationTime, b.preparationTime);
}

int Recipe::compareByInstructions(const Recipe& a, const Recipe& b) {
    return a.instructions.compare(b.instructions);
}

int Recipe::compareByAuthor(const Recipe& a, const Recipe& b) {
    return Name::compare(a.author, b.author);
}

string Recipe::serialize() const {}

void Recipe::deserialize(const string&) {}

istream& operator >> (istream& is, Recipe& r) {
    string myStr;

    getline(is, myStr, ';');
    r.name = myStr;
    is >> r.ingredientList;
    is >> r.preparationTime;
    getline(is, myStr, ';');
    r.instructions = myStr;
    is >> r.author;
    getline(is, myStr, ';');
    r.category = myStr;

    return is;
}

ostream& operator << (ostream& os, const Recipe& r) {
    os << r.name << ';';
    os << r.ingredientList; 
    os << r.preparationTime;
    os << r.instructions << ';';
    os << r.author << ';';
    os << r.category << '#';

    return os;

}
