#include "recipeinterface.hpp"

using namespace std;

void RecipeInterface::menu() {
    cout << "╔══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗" << endl;
    cout << "║																     														║" << endl;
    cout << "║																     														║" << endl;
    cout << "║																      														║" << endl;
    cout << "║		██████╗ ███████╗ ██████╗███████╗ ████████╗ █████╗   ██████╗██╗  ██████╗ 			     							║" << endl;
    cout << "║		██╔══██╗██╔════╝██╔════╝██╔════╝╚══ ██╔══╝██╔══██ ╗██╔══██╗██║ ██╔══██╗			     								║" << endl;
    cout << "║		██████╔╝█████╗  ██║     █████╗      ██║   ███████ ║██████╔╝██║ ██║   ██║                          				    ║" << endl;
    cout << "║		██╔══██╗██╔══╝  ██║     ██╔══╝      ██║   ██╔══██ ║██╔══██╗██║ ██║   ██║		      	     					    ║" << endl;
    cout << "║		██║  ██║███████╗╚██████╗███████╗    ██║   ██║  ██ ║██║  ██ ██║ ╚██████╔╝			     							║" << endl;
    cout << "║		╚═╝  ╚═╝╚══════╝ ╚═════╝╚══════╝    ╚═╝    ╚═╝  ╚═╝╚═╝   ╚═╝ ╚═╝╚═════╝ 			     							║" << endl;
    cout << "║                                                                     								     					║" << endl;
    cout << "║		██████╗ ██╗ ██████╗ ██╗ ████████╗ █████╗ ██╗                          				     							║" << endl;
    cout << "║		██╔══██╗██║██╔════╝ ██║╚══ ██╔══╝██╔══██╗██║                          				     							║" << endl;
    cout << "║		██║  ██║██║██║  ███╗██║    ██║   ███████║██║                          					     						║" << endl;
    cout << "║		██║  ██║██║██║   ██║██║    ██║   ██╔══██║██║                          					     						║" << endl;
    cout << "║		██████╔╝██║╚██████╔╝██║    ██║   ██║  ██║███████╗                     				      							║" << endl;
    cout << "║		╚═════╝ ╚═╝ ╚═════╝ ╚═╝    ╚═╝   ╚═╝  ╚═╝╚══════╝                     				     							║" << endl;
    cout << "║                   © Esqueda Patiño Emmanuel Moises                                  			    						║" << endl;
    cout << "║               								     																	 	║" << endl;
    cout << "║  					Presione [ENTER] para continuar...					                     							║" << endl;
    cout << "║																     														║" << endl;
    cout << "╚══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝" << endl;     
    cin.get();
}
void RecipeInterface::mainMenu() {
    int opc;
    do{
        cout << "***********************" << endl;
        cout << "*    Menú Principal   *" << endl;
        cout << "***********************" << endl;
        cout << "1. Agregar receta" << endl;
        cout << "2. Eliminar receta" << endl;
        cout << "3. Editar receta" << endl;
        cout << "4. Mostrar lista de recetas" << endl;
        cout << "5. Ordenar recetas" << endl;
        cout << "6. Guardar recetas en disco" << endl;
        cout << "7. Cargar recetas desde disco" << endl;
        cout << "8. Eliminar todas las recetas" << endl;
        cout << "9. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opc;
        cin.ignore();

        switch (opc) {
            case 1:
                this->addRecipe();
                break;
            case 2:
                this->delRecipe();
                break;
            case 3:
                this->editRecipe();
                break;
            case 4:
                this->showList();
                break;
            case 5:
                this->sortData();
                break;
            case 6:
                this->writeToDisk();
                break;
            case 7:
                this->readFromDisk();
                break;
            case 8:
                this->delAllRecipes();
                break;
            case 9:
                cout << "Saliendo del programa..." << endl;
                this->enterToContinue();
                break;
            default:
                cout << "Opción inválida. Por favor, seleccione una opción válida." << endl;
        }

    } while(opc != 8);
    
    
}

void RecipeInterface::addRecipe() {
    string myStr;
    Time myTime;
    Name myName;
    int categoryOpc;
    char op;
    
    do{
        Recipe myRecipe;
        cout << "Agregar receta" << endl;
        cout << "Ingrese el nombre de la receta: ";
        getline(cin, myStr);
        myRecipe.setName(myStr);

        cout << "Ingrese el tiempo de preparacion (HH:MM): ";
        getline(cin, myStr, ':');

        myTime.setHours(stoi(myStr));

        getline(cin, myStr);
        myTime.setMinutes(stoi(myStr));

        myRecipe.setPreparationTime(myTime);

        cout << "Ingrese el procedimiento de la receta: ";
        getline(cin, myStr);
        myRecipe.setInstructions(myStr);

        cout << "Ingrese el autor de la receta: " << endl;
        cout << "Apellido: ";
        getline(cin, myStr);
        myName.setLast(myStr);

        cout << "Nombre: ";
        getline(cin, myStr);
        myName.setFirst(myStr);

        myRecipe.setAuthor(myName);

        do{
            cout << "Categoría de la receta " << endl;
            cout << "1. Desayuno" << endl;
            cout << "2. Comida" << endl;
            cout << "3. Cena" << endl;
            cout << "4. Navidad" << endl;
            cout << "Seleccione una opción: ";
            cin >> categoryOpc;
            cin.ignore();

            switch (categoryOpc) {
                case 1:
                    myRecipe.setCategory("Desayuno");
                    break;
                case 2:
                    myRecipe.setCategory("Comida");
                    break;
                case 3:
                    myRecipe.setCategory("Cena");
                    break;
                case 4:
                    myRecipe.setCategory("Navidad");
                    break;

                default:
                    cout << "Opción inválida. Por favor, seleccione una opción válida." << endl;
                    break;
            
            }

        } while(categoryOpc < 1 || categoryOpc > 4);

    IngredientInterface ingredientInterface(myRecipe.getListIngredient());
    ingredientInterface.mainMenu();

    this->myListRef->instData(this->myListRef->getLastPos(), myRecipe);

    cout << "Receta agregada exitosamente." << endl;
    this->enterToContinue();

     cout << "¿Desea agregar otra receta? (s/n): ";
        cin >> op;
        op = toupper(op);
        cin.ignore();

        do{
        if(op != 'S' && op != 'N'){
            cout << "Opción inválida." << endl; 
            this->enterToContinue();
        }
        } while (op != 'S' && op != 'N');


    } while(op == 'S');

}

void RecipeInterface::delRecipe() {
    string name;
    Recipe myRecipe;
    char op;
    int pos;

    cout << "Ingrese el nombre de la receta a eliminar: ";
    getline(cin, name);
    myRecipe.setName(name);
    pos = this->myListRef->findData(myRecipe);
    if (pos != -1) {
        this->myListRef->delData(pos);
        cout << "Receta eliminada." << endl;
        this->enterToContinue();
    } else {
        cout << "Receta no encontrada." << endl;
        this->enterToContinue();
    }
}

void RecipeInterface::delAllRecipes(){
    char op;
    
    cout << "¿Estas seguro de que desea eliminar todas las recetas?, esta acción no se puede deshacer. (s/n): ";
    cin >> op;
    op = toupper(op);
    cin.ignore();

    if(op == 'S'){
        this->myListRef->delAll();
        cout << "Todas las recetas han sido eliminadas." << endl;
        this->enterToContinue();
    } else {
        cout << "Operación cancelada." << endl;
        this->enterToContinue();
    }
}

void RecipeInterface::editRecipe() {
    string myStr;
    Recipe searchRecipe;
    int pos, editOpc;
    char op;
    Time myTime;
    Name myName;

    cout << "Nombre de la receta a editar: ";
    getline(cin, myStr);
    searchRecipe.setName(myStr);
    pos = this->myListRef->findDataL(searchRecipe);
    if (pos != -1) {
        Recipe& recipeToEdit = this->myListRef->retreive(pos);

        do{
        cout << "Que desea editar?" << endl;
        cout << "1. Nombre" << endl;
        cout << "2. Tiempo de preparación" << endl;
        cout << "3. Procedimiento" << endl;
        cout << "4. Autor" << endl;
        cout << "5. Categoría" << endl;
        cout << "6. Ingredientes" << endl;
        cout << "Seleccione una opción: ";

        cin >> editOpc;
        cin.ignore();

        switch (editOpc)
        {
        case 1:
            cout << "Ingrese el nuevo nombre de la receta: ";
            getline(cin, myStr);
            recipeToEdit.setName(myStr);
            break;
        case 2:
            cout << "Ingrese el nuevo tiempo de preparación (HH:MM): ";
            getline(cin, myStr, ':');
            myTime.setHours(stoi(myStr));
            getline(cin, myStr);
            myTime.setMinutes(stoi(myStr)); 

            recipeToEdit.setPreparationTime(myTime);
            break;
        case 3:
            cout << "Ingrese el nuevo procedimiento: ";
            getline(cin, myStr);
            recipeToEdit.setInstructions(myStr);
            break;
        case 4:
            cout << "Ingrese el nuevo autor: " << endl;
            cout << "Apellido: ";
            getline(cin, myStr);
            recipeToEdit.getAuthor().setLast(myStr);
            cout << "Nombre: ";
            getline(cin, myStr);
            recipeToEdit.getAuthor().setFirst(myStr);
            break;
        case 5:
            cout << "Ingrese la nueva categoría: ";
            getline(cin, myStr);
            recipeToEdit.setCategory(myStr);
            break;
        case 6: {
            IngredientInterface ingredientInterface(recipeToEdit.getListIngredient());
            ingredientInterface.mainMenu();
            break;
        }
        
        default:
            cout << "Opción inválida." << endl;
            break;
        }

        if (!(editOpc < 1 || editOpc > 6)) {

            cout << "¿Estas seguro de que desea eliminar todas las recetas?, esta acción no se puede deshacer. (s/n): ";
            cin >> op;
            op = toupper(op);
            cin.ignore();

            if(op == 'S'){
                this->myListRef->delAll();
                cout << "Todas las recetas han sido eliminadas." << endl;
                this->enterToContinue();
            } 
            else {
                cout << "Operación cancelada." << endl;
                this->enterToContinue();
            }

            }

        } while(editOpc < 1 || editOpc > 6);


        cout << "Receta editada exitosamente." << endl;
        this->enterToContinue();
    } else {
        cout << "Receta no encontrada." << endl;
        this->enterToContinue();
    }
}

void RecipeInterface::showList() {
    char op;
    int pos(this->myListRef->getFirstPos());

    if (this->myListRef->isEmpty()) {
        cout << "La lista de recetas está vacía." << endl;
    } 
    else {
        cout <<"Con ingredientes o sin ingredientes? (s/n): ";
        cin >> op;
        cin.ignore();
        op = toupper(op);
        if(op == 'S'){
            cout << "Lista de recetas con ingredientes:" << endl;
            while(pos != -1){
                cout << this->myListRef->retreive(pos).toString(true);

                pos = this->myListRef->getNextPos(pos);
            }

        }
            else {
                cout << "Lista de recetas sin ingredientes:" << endl;
                cout << this->myListRef->toString();
            }
        
    }
}

void RecipeInterface::searchRecipe()
{
    
}

void RecipeInterface::sortData() {
    int opc;
    do{
        cout << "Como quieres oredenar las recetas?";
        cout << "1. Por Nombre";
        cout << "2. Por tiempo de preparacion";
        switch (opc) {
        case 1:
            this->myListRef->sortDataQuick(Recipe::compareByName);
            break;
        case 2:
            this->myListRef->sortDataQuick(Recipe::compareByPreparationTime);
            break;
        
        default:
            cout << "Opcion Invalida" << endl;
            break;
        }
    } while(opc < 1 || opc < 2);
}

void RecipeInterface::writeToDisk() {
    cout << "opc en mantenimiento" << endl;
}

void RecipeInterface::readFromDisk() {
    cout << "opc en mantenimiento" << endl;
}

void RecipeInterface::enterToContinue() {
    cout << "Presione [ENTER] para continuar...";
    cin.get();
    cout << endl << endl;
}


RecipeInterface::RecipeInterface(List<Recipe>& l) : myListRef(&l) {
    this->menu();
    this->mainMenu();
}


