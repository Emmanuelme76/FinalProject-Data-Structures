# Pendientes

## Menu Principal
-[x] La opcion de salir no funciona bien

## toString

## Solucionar Categoria
- [x] Debo de solucionar porque las categorias no aparecen, quizas sea un problema del constructor o del **operador de asignacion!!** (si era)
- [ ] Debo de implementar logica que filtre por categorias

## Escritura al disco
- [ ]Debo implementar una logica para escribir al disco

## Editar Receta

### Menu general
Creo que el menu de editar no edita nada
- [x] Los nombres no se editan (_Se arreglo con un_ ***&***)

- [x] El autor no se edita (La sintaxis estaba medio rara)

- [x] El menu de categorias no es de seleccion

- [x] Arreglar todo el menu

Posibles hipotesis del mal funcionamiento:
- La interfaz de editar receta está rota

#### Soluciones
- Usar una referencia ***&*** para editar el objeto original y no la copia de este 

- Para la Busqueda de ingredientes se usó una funcion explicita porque al parecer rcurria al operador `==` y se tenia implementado que regresara nombre y cantidad en ese operador

### Ingredientes
- [x] El Menu de ingredientes en la parte de eliminar no funciona la caracteristica principal
 
- [x] Editar Ingredientes no edita la lista original
    - [x] El problema ahora es volver a ordenar el ingrediente si se cambia su nombre, asi que debo de quitar la modificacion le nombre, reciclar insertSortedData o reescribirlo ahí mismo (El insertSortedData), (Al final la solución fue la segunda opcion, eliminarlo y volverlo a insertar, esto con ayuda de un auxiliar).

- [x] Hay opciones que marca como invalidas pero son validas

- [x] ~~La busqueda de ingredientes no funciona~~  

Mi hipotesis principal es que probablemente la problematica no esté en la interfaz de ingredientes
- [x] ~~no funciona el (s/n) de eliminar ingredientes~~

## Buscar Receta
- [ ] Implementar un metodo de busqueda de receta a través del nombre del platillo, o bien a través de su categoría (el primero en encontrarse) (Debo hacer comparaciones explicitas)

## Agregar Receta
### Ingredientes
- [x] Los ingredientes no se orden bien en algunas recetas


## Historial
### toSring
- [x] El toString de recipeInterface no filtra por lista de recetas
- [x] Los ingredientes se comportan extraño en las ultimas recetas
- [x] Se debe mejorar el menu de ingredientes colocando otra condicion al do-while 
- [x] **ERROR CRITICO** al intentar insertar los ingredientes, el bucle que coloque tiene una logica incorrecta



