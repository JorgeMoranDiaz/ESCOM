# MAKEFILE EJEMPLO
## Proyecto
Creación, análisis y ejecución de un makefile comprender sus funcionalidades, ventajas, y utilizarlos en futuros proyectos.

## Ejecucion del codigo
  1. Acceder a una computadora con sistema operativo linux
  2. Colocar los siguientes archivos en el mismo directorio:
       - **Makefile** (sin extension)
       - **main.c**
  3. Abrir la terminal de comandos
  4. Moverse al directorio donde se guardaron los archivos con **cd**
     - Ejemplo: `giorgimd@Ubuntu:~$ cd /Documents/IoT/Makefile`
  5. Compilar el codigo en C con **make** y deben de aparecer los comandos que ejecutó make
     - Ejemplo: ```giorgimd@Ubuntu:~/Documents/IoT/Makefile$ make,
                 gcc -Wall -Wextra -O2 -c main.c -o main.o
                 gcc -Wall -Wextra -O2 main.o -o hola```
  6. Ejecutar el programa con **./nombre**
     - Ejemplo: ```giorgimd@Ubuntu:~/Documents/IoT/Makefile$ ./hola
                 Hola desde un ejemplo basico de Makefile.
                 Este programa fue compilado y ejecutado con make.```
