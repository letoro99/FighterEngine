# FighterEngine
Motor de juego creado por Álvaro Toro que se centrá en la creación de videojuegos del género de Pelea con ciertos toques de Plataformas como lo vendria siendo SuperSmashBros, Rivals of Aether y Brawhalla. Se desea generar la opción para que el campo de pelea sea en 2 que puede ser usado con modelos 2D y 3D. El motor fue creado usando el lenguaje de programación C++ haciendo uso de librerias que se encuentran en el mismo lenguaje.

Inicialmente este motor se centrará en inputs simples restringiendo a no tener más de 4 botones para los golpes.

## Librerias de 3eros usadas
- GLFW
- OpenGL

## Instrucciones de compilación
Se debe usar VisualStudio 2022 y CMAKE.

Se debe ejecutar los siguientes comandos para los submodulos de las librerias externas
- dentro del repositorio: git submodule update --init --recursive
- Se debe construir las librerias en Release dentro de una carpeta build al lado de source.
  - mkdir libs\glfw\build
  - cd libs\glfw\build
  - cmake ..\source\glfw\
  - Se debe abrir el .sln de la carpeta build
  - Construir la solucion en Release
- Se debe repetir esto mismo con las demás librerias.

Para poder ejecutar la demos debe realizar lo siguiente.
 - mkdir app\build
 - cd app\build
 - cmake ..\source\
 - abrir el .snl creado por cmake
 - Construir la solucion en Release o Debug.
Con eso se debería crear si o si el ejecutable junto a una libreria estática que sería el engine.
