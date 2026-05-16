#include "ingredientinterface.hpp"

using namespace std;

void IngredientInterface::mainMenu() {
  int opc;

  do {
    do {
      cout << "Menu de Ingredientes" << endl;
      cout << "1. Agregar ingrediente" << endl;
      cout << "2. Eliminar ingrediente" << endl;
      cout << "3. Editar ingrediente" << endl;
      cout << "4. Mostrar lista de ingredientes" << endl;
      cout << "5. Eliminar todos los ingredientes" << endl;
      cout << "6. Salir" << endl;
      cout << "Seleccione una opción: ";
      cin >> opc;
      cin.ignore();

      switch (opc) {
        case 1:
          this->addIngredient();
          break;
        case 2:
          this->delIngredient();
          break;
        case 3:
          this->editIngredient();
          break;
        case 5:
          this->delAllIngredients();
          break;
        case 4:
          this->showList();
          break;
        case 6:
          cout << "Saliendo del menú de ingredientes..." << endl;
          this->enterToContinue();
          break;
        default:
          cout << "Opción inválida. Por favor, seleccione una opción válida."
               << endl;
      }
    } while (opc < 1 && opc > 6);
  } while (opc != 6 && opc != 1);
}

void IngredientInterface::addIngredient() {
  string name, amount;
  Ingredient myIngredient;
  char op;

  do {
    cout << "Ingrese el nombre del ingrediente: ";
    getline(cin, name);
    myIngredient.setName(name);

    cout << "Ingrese la cantidad del ingrediente: ";
    getline(cin, amount);
    myIngredient.setAmount(amount);

    this->myListRef->insertSortedData(myIngredient);
    do {
      cout << "¿Desea agregar otro ingrediente? (s/n): ";
      cin >> op;
      op = toupper(op);
      cin.ignore();

      if (op != 'S' && op != 'N') {
        cout << "Opción inválida." << endl;
        this->enterToContinue();
      }
    } while (op != 'S' && op != 'N');

  } while (op == 'S');
}

void IngredientInterface::delIngredient() {
  string name;
  Ingredient myIngredient;
  char op;
  SLList<Ingredient>::Position pos;

  do {
    cout << "Ingrese el nombre del ingrediente a eliminar: ";
    getline(cin, name);
    myIngredient.setName(name);

    pos = this->myListRef->findData(myIngredient, Ingredient::compareByName);
    if (pos != nullptr) {
      this->myListRef->delData(pos);
      cout << "Ingrediente eliminado." << endl;
      this->enterToContinue();
    } else {
      cout << "Ingrediente no encontrado." << endl;
      this->enterToContinue();
    }

    cout << "¿Desea eliminar otro ingrediente? (s/n): ";
    cin >> op;
    op = toupper(op);
    cin.ignore();

    do {
      if (op != 'S' && op != 'N') {
        cout << "Opción inválida." << endl;
        this->enterToContinue();
      }
    } while (op != 'S' && op != 'N');

  } while (op == 'S');
}

void IngredientInterface::delAllIngredients() {
  char op;

  cout << "¿Estas seguro de que desea eliminar todos los ingredientes?, esta "
          "acción no se puede deshacer. (s/n): ";
  cin >> op;
  op = toupper(op);
  cin.ignore();

  if (op == 'S') {
    this->myListRef->delAll();
    cout << "Todos los ingredientes han sido eliminados." << endl;
    this->enterToContinue();
  } else {
    cout << "Operación cancelada." << endl;
    this->enterToContinue();
  }
}

void IngredientInterface::editIngredient() {
  string name;
  Ingredient searchIngredient;
  SLList<Ingredient>::Position pos;
  int opc;

  cout << "Ingrese el nombre del ingrediente a editar: ";
  getline(cin, name);
  searchIngredient.setName(name);
  pos = this->myListRef->findData(searchIngredient, Ingredient::compareByName);
  if (pos != nullptr) {
    Ingredient& myIngredient = this->myListRef->retrieve(pos);

    do {
      cout << "Ingrediente actual: " << myIngredient.getName() << " - "
           << myIngredient.getAmount() << endl;

      cout << "¿Qué deseas editar?" << endl;
      cout << "1. Nombre" << endl;
      cout << "2. Cantidad" << endl;
      cout << "Seleccione una opción: ";
      cin >> opc;
      cin.ignore();
      switch (opc) {
        case 1: {
          string nuevoNombre;
          cout << "Ingrese el nuevo nombre: ";
          getline(cin, nuevoNombre);
          myIngredient.setName(nuevoNombre);
          break;
        }
        case 2: {
          string nuevaCantidad;
          cout << "Ingrese la nueva cantidad: ";
          getline(cin, nuevaCantidad);
          myIngredient.setAmount(nuevaCantidad);
          break;
        }
        default:
          cout << "Opción inválida." << endl;
          this->enterToContinue();
      }
    } while (opc < 1 or opc > 2);
    cout << "Ingrediente editado." << endl;
    this->enterToContinue();

    // Esto resuelve la problematica de que al editar el nombre
    // del ingrediente La insercion ordenada no se vea afectada

    Ingredient aux = myIngredient;
    myListRef->delData(pos);
    this->myListRef->insertSortedData(aux);
  } else {
    cout << "Ingrediente no encontrado." << endl;
    this->enterToContinue();
  }
}

void IngredientInterface::showList() {
  if (this->myListRef->isEmpty()) {
    cout << "La lista de ingredientes está vacía." << endl;
  } else {
    cout << "Lista de ingredientes:" << endl;
    cout << "Ingrediente - Cantidad" << endl;
    cout << this->myListRef->toString();
  }
  this->enterToContinue();
}

void IngredientInterface::enterToContinue() {
  cout << "Presione [ENTER] para continuar..." << endl;
  cin.get();
}

IngredientInterface::IngredientInterface(SLList<Ingredient>& l)
    : myListRef(&l) {}
