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
        cout << "*                     *" << endl;
        cout << "*    Menú Principal   *" << endl;
        cout << "*                     *" << endl;
        cout << "***********************" << endl << endl;
        cout << "1. Agregar receta" << endl << endl;
        cout << "2. Eliminar receta" << endl << endl;
        cout << "3. Editar receta" << endl << endl;
        cout << "4. Buscar una receta" << endl << endl;
        cout << "5. Mostrar lista de recetas" << endl << endl;
        cout << "6. Ordenar recetas" << endl << endl;
        cout << "7. Guardar recetas en disco" << endl << endl;
        cout << "8. Cargar recetas desde disco" << endl << endl;
        cout << "9. Eliminar todas las recetas" << endl << endl;
        cout << "10. Salir" << endl << endl;
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
                this->searchRecipe();
                break;
            case 5:
                this->showList();
                break;
            case 6:
                this->sortData();
                break;
            case 7:
                this->writeToDisk();
                break;
            case 8:
                this->readFromDisk();
                break;
            case 9:
                this->delAllRecipes();
                break;
            case 10:
                cout << "Saliendo del programa..." << endl;
                this->enterToContinue();
                break;
            default:
                cout << "Opción inválida. Por favor, seleccione una opción válida." << endl << endl;
        }

    } while(opc != 10);
    
    
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

    this->myListRef->insData(this->myListRef->getLastPos(), myRecipe);

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
    DLList<Recipe>::Position pos;

    cout << "Ingrese el nombre de la receta a eliminar: ";
    getline(cin, name);
    myRecipe.setName(name);
    pos = this->myListRef->findData(myRecipe);
    if (pos != nullptr) {
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
    int editOpc, categoryOpc;
    char op;
    Time myTime;
    Name myName;
    DLList<Recipe>::Position pos;

    cout << "Nombre de la receta a editar: ";
    getline(cin, myStr);
    searchRecipe.setName(myStr);
    pos = this->myListRef->findData(searchRecipe);
    if (pos != nullptr) {
        Recipe& recipeToEdit = this->myListRef->retrieve(pos);

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
            myName.setLast(myStr);
            cout << "Nombre: ";
            getline(cin, myStr);
            myName.setFirst(myStr);

            recipeToEdit.setAuthor(myName);
            break;
        case 5:
            do{
                cout << "Ingrese la nueva categoría: " <<endl << endl;
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
                            recipeToEdit.setCategory("Desayuno");
                            break;
                        case 2:
                            recipeToEdit.setCategory("Comida");
                            break;
                        case 3:
                            recipeToEdit.setCategory("Cena");
                            break;
                        case 4:
                            recipeToEdit.setCategory("Navidad");
                            break;

                        default:
                            cout << "Opción inválida. Por favor, seleccione una opción válida." << endl;
                            break;
                        }

                }  while(categoryOpc < 1 || categoryOpc > 4); 
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

            
            do{
                cout << "Deseas editar otro elemento de la Receta?. (s/n): ";
                cin >> op;
                op = toupper(op);
                cin.ignore();
            
               if(op != 'S' && op != 'N'){
               cout << "Opción inválida." << endl; 
               this->enterToContinue();
               }
           } while (op != 'S' && op != 'N');

            if(op == 'S'){
                editOpc = 0;
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
    DLList<Recipe>::Position pos(this->myListRef->getFirstPos());
    int opcFilt;
    Recipe myRecipe;
    string category;
    
    if (this->myListRef->isEmpty()) {
        cout << "La lista de recetas está vacía." << endl;
    } 
    else {
        do{

            cout << "Filtrar recetas por categoria?" << endl;
            cout << "1. Desayuno" << endl;
            cout << "2. Comida" << endl;
            cout << "3. Cena" << endl;
            cout << "4. Navidad" << endl;
            cout << "5. Mostrar todas las recetas" << endl;
            cout << "Selecciona una opcion: ";
            cin >> opcFilt;
            cin.ignore();

            if(opcFilt < 1 || opcFilt > 5) {
                cout << "Opcion invalida, elija una opcion valida" << endl;
            }

        } while (opcFilt < 1 || opcFilt > 5);

        switch (opcFilt)
        {
        case 1:
            myRecipe.setCategory("Desayuno");
            category = myRecipe.getCategory();
            break;
        case 2:
            myRecipe.setCategory("Comida");
            category = myRecipe.getCategory();
            break;
        case 3:
            myRecipe.setCategory("Cena");
            category = myRecipe.getCategory();
            break;
        case 4:
            myRecipe.setCategory("Navidad");
            category = myRecipe.getCategory();
            break;
        case 5:
            do {
                cout <<"Con ingredientes o sin ingredientes? (s/n): ";
                cin >> op;
                cin.ignore();
                op = toupper(op);
                if(op != 'S' && op != 'N'){
                    cout << "Opción inválida." << endl; 
                    this->enterToContinue();
               }
           } while (op != 'S' && op != 'N');
            if(op == 'S'){
                cout << "Lista de recetas con ingredientes:" << endl;
                while(pos != nullptr){
                    cout << this->myListRef->retrieve(pos).toString(true);

                    pos = this->myListRef->getNextPos(pos);
                }

            }
                else {
                    cout << "Lista de recetas sin ingredientes:" << endl;
                    cout << this->myListRef->toString();
                }

            break;

        default:
            cout << "Opción inválida. Por favor, seleccione una opción válida." << endl;
            break;
        }

        if (opcFilt >= 1 && opcFilt < 5) {
             do {
                cout <<"Con ingredientes o sin ingredientes? (s/n): ";
                cin >> op;
                cin.ignore();
                op = toupper(op);
                if(op != 'S' && op != 'N'){
                    cout << "Opción inválida." << endl; 
                    this->enterToContinue();
               }
           } while (op != 'S' && op != 'N');

           if(op == 'S'){
                cout << "Lista de recetas con ingredientes:" << endl << endl;
                while(pos != nullptr){

                    if((this->myListRef->retrieve(pos).getCategory()) == category) {
                       cout << this->myListRef->retrieve(pos).toString(true);
                    }

                    pos = this->myListRef->getNextPos(pos);
                }

            }
                else {
                    cout << "Lista de recetas sin ingredientes:" << endl << endl;
                    while(pos != nullptr){

                    if((this->myListRef->retrieve(pos).getCategory()) == category) {
                        cout << this->myListRef->retrieve(pos).toString() << endl;
                    }

                    pos = this->myListRef->getNextPos(pos);
                }
                }

        }


        
    }
}

void RecipeInterface::searchRecipe() {
    string myStr;
    int opc, categoryOpc;
    Recipe myRecipe;
    DLList<Recipe>::Position pos;

    do{
        cout << "Criterio de busqueda" << endl;
        cout << "1. Nombre del platillo" << endl;
        cout << "2. Categoria" << endl;
        cin >> opc;
        cin.ignore();
        if(opc < 1 || opc > 2){
            cout << "Opcion invalida, escoge una opcion valida" << endl;
        }
    } while(opc < 1 || opc > 2);

    if (opc == 1) {
        cout << "Nombre de la receta a encontrar: ";
        getline(cin, myStr);
        myRecipe.setName(myStr);
        
        pos = this->myListRef->findData(myRecipe);
    
        if (pos != nullptr) {
            cout << "Receta encontrada!" << endl << endl;
            Recipe &newRecipe = this->myListRef->retrieve(pos);
            cout << newRecipe.toString(true);
        }
        else {
            cout << "La receta no se encontro" << endl;
        }

    }
    else {
        
         do{
                cout << "Ingrese la categoría: " <<endl << endl;
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

                }  while(categoryOpc < 1 || categoryOpc > 4);
                pos = this->myListRef->findData(myRecipe, Recipe::compareByCategory);
                Recipe &newRecipe = this->myListRef->retrieve(pos);
                
                cout << newRecipe.toString(true);   
    }

}

void RecipeInterface::sortData() {
    int opc;
    do{
        cout << "Como quieres oredenar las recetas?" << endl;
        cout << "1. Por Nombre" << endl;
        cout << "2. Por tiempo de preparacion" << endl;
        cout << "Selecciona una opcion: ";
        cin >> opc;
        cin.ignore();

        switch (opc) {
        case 1:
            this->myListRef->sort(Recipe::compareByName);
            break;
        case 2:
            this->myListRef->sort(Recipe::compareByPreparationTime);
            break;
        
        default:
            cout << "Opcion Invalida" << endl;
            break;
        }
    } while(opc < 1 || opc > 2);

    if((this->myListRef->isSorted(Recipe::compareByName)) ||
       (this->myListRef->isSorted(Recipe::compareByPreparationTime))) {
        cout << "La lista se ordeno" << endl;
    }
    else {
        cout << "La lista no se pudo ordenar" << endl;
    }
}

void RecipeInterface::writeToDisk() {
    string fileName;

    cout << "Escritura al Disco" << endl << endl;
    
    cout << "Nombre del archivo: ";
    getline(cin, fileName);

    cout << endl << endl;

    ofstream myFile(fileName, ios_base::trunc);
    
    if (myFile.is_open()) {
        cout << "Escribiendo al archivo..." << endl;
        myFile << this->myListRef->serialize();
        myFile.close();
        cout << "Archivo Escrito exitosamente" << endl;

        this->enterToContinue();
    } 
    else {
        cout << "Error al abrir el Archivo" << fileName << " no se pudo abrir para escritura" << endl;
        this->enterToContinue();
    }

}

void RecipeInterface::readFromDisk() {
    string fileName, fileStr;

    cout << "Leer al disco" << endl << endl;
    
    cout << "Nombre del archivo: ";
    getline(cin, fileName);

    ifstream myFile(fileName);
    if (myFile.is_open()) {
        cout << "Leyendo el archivo..." << endl;
        getline(myFile, fileStr);
        myFile.close();
        this->myListRef->deserialize(fileStr);
        cout << "Archivo Leido" << endl;
        this->enterToContinue();

    } 
    else {
        cout << "Error al abrir el Archivo" << endl;
        this->enterToContinue();
    }
}

void RecipeInterface::enterToContinue() {
    cout << "Presione [ENTER] para continuar...";
    cin.get();
    cout << endl << endl;
}


RecipeInterface::RecipeInterface(DLList<Recipe>& l) : myListRef(&l) {
    this->menu();
    this->mainMenu();
}


