# MAKEFILE EJEMPLO

## Proyecto
Creación, análisis y ejecución de un makefile para comprender sus funcionalidades, ventajas y utilizarlos en futuros proyectos.

## Ejecucion del codigo
1. Acceder a una computadora con sistema operativo Linux.
2. Colocar los siguientes archivos en el mismo directorio:
   - **Makefile** (sin extension)
   - **main.c**
3. Abrir la terminal de comandos.
4. Moverse al directorio donde se guardaron los archivos con **cd**.
   Ejemplo:
   ```bash
   giorgimd@Ubuntu:~$ cd /Documents/IoT/Makefile
   ```
5. Compilar el codigo en C con **make** y deben aparecer los comandos que ejecutó `make`.
   Ejemplo:
   ```bash
   giorgimd@Ubuntu:~/Documents/IoT/Makefile$ make
   gcc -Wall -Wextra -O2 -c main.c -o main.o
   gcc -Wall -Wextra -O2 main.o -o hola
   ```
6. Ejecutar el programa con **./nombre**.
   Ejemplo:
   ```bash
   giorgimd@Ubuntu:~/Documents/IoT/Makefile$ ./hola
   Hola desde un ejemplo basico de Makefile.
   Este programa fue compilado y ejecutado con make.
   ```
7. Con lo anterior veremos que en el directorio se habrán creado el archivo .o y el ejecutable
