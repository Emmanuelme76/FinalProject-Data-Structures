## ¿Cómo Instalar el Recetario Digital?
---
###  Para Windows
Necesitas Instalar un  compilador de C/C++ para poder ejecutar el Recetario. Una propuesta de compilador es: **MSYS2**

1. Instalar el compilador del siguiente enlace:

>[!NOTE]
>Debes seguir las instrucciones del siguiente enlace que te ayudaran a instalar el compilador

[MSYS2](https://www.msys2.org/) 

2. Debes de saber la ubicación de la carpeta del recetario. 
3. Lo siguiente es abrir **PowerShell** y escribir el comando `cd`  hasta saber la ubicación del proyecto 
>[!NOTE]
>También puedes ayudarte del comando `ls` para ver la lista de archivos y carpetas en tu directorio actual

Ejemplo de como se vería en el escritorio
~~~ powershell
cd C:\Users\emman\Desktop\ProyectoFinal\FinalProyect\
~~~
o también puedes escribir en la barra de rutas **PowerShell** para abrir directamente la consola en la ubicación
![[Pasted image 20260516190441.png]]

4. Lo siguiente que debes hacer es ingresar el siguiente comando:

~~~powershell
g++ src/*.cpp -I include -o recetario.exe
~~~

5. Por ultimo ejecutas esta comando:

~~~powershell
.\recetario.exe
~~~

Ejemplo de como se ve todo:

![[Pasted image 20260516190948.png]]

### Para Linux(Ubuntu/Debian):

1. **Instalar el compilador.** Abre la terminal y ejecuta el siguiente comando:

~~~Bash
sudo apt update 
sudo apt install build-essential
~~~

2. **Ejecución.** Debes moverte a la carpeta del proyecto y ejecutar lo siguiente:

~~~Bash
g++ src/*.cpp -I include -o recetario 
./recetario
~~~

### Para macOS

1. **Instalar el compilador.** Abre la terminal y ejecuta el siguiente comando:

~~~Bash
xcode-select --install
~~~

>[!NOTE]
> Debes aceptar la confirmación que aparece en la pantalla emergente

2. **Ejecución.** Debes moverte a la carpeta del proyecto y ejecutar lo siguiente:

~~~Bash
g++ src/*.cpp -I include -o recetario 
./recetario
~~~

