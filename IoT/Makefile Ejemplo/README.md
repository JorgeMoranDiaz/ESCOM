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
 **Con lo anterior veremos que en el directorio se habrán creado el archivo .o y el ejecutable**
 
   ![directorio con archivos creados](img/Directorio.png)
   
 ### Extra
   - Para obtener ayuda sobre las demas opciones disponibles utilizar **help** 
   Ejemplo:
   ```bash
   giorgimd@Ubuntu:~/Documents/IoT/Makefile$ make help
   Objetivos disponibles:
     make         -> compila el programa
     make run     -> compila y ejecuta
     make clean   -> elimina archivos generados
     make rebuild -> limpia y vuelve a compilar
   ```
   - make run: compila y ejecuta el programa en un solo comando sin usar make y ./ separados.
   - make clean: elimina el archivo .o y ejecutable que fueron creados al compilar el programa del directorio.
   - make rebuild: elimina los archivos creados y compila nuevamente **sin ejecutar**.

## Explicación del codigo
   ```bash
   # =========================
   # MACROS
   # =========================
   
   # Definir el compilador
   CC = gcc
   
   # Banderas para el compilador
   CFLAGS = -Wall -Wextra -O2
   
   # Nombre del ejecutable final
   TARGET = hola
   
   # Archivo fuente del proyecto
   SRCS = main.c
   
   # Reemplaza main.c por main.o
   OBJS = $(SRCS:.c=.o)
   
   # Estos objetivos no representan archivos reales
   .PHONY: all run clean help rebuild
   
   
   # Objetivo por defecto: compilar el programa
   all: $(TARGET)
   
   
   # Muestra ayuda con los comandos disponibles
   help:
   	@echo "Objetivos disponibles:"
   	@echo "  make         -> compila el programa"
   	@echo "  make run     -> compila y ejecuta"
   	@echo "  make clean   -> elimina archivos generados"
   	@echo "  make rebuild -> limpia y vuelve a compilar"
   
   
   # Regla patrón:
   # Para construir cualquier archivo .o, se necesita su archivo .c con el mismo nombre
   # Ejemplo:
   # gcc -Wall -Wextra -O2 -c main.c -o main.o
   %.o: %.c
   	$(CC) $(CFLAGS) -c $< -o $@
   
   
   # Construye el ejecutable final a partir de los archivos objeto
   # Ejemplo:
   # gcc -Wall -Wextra -O2 main.o -o hola
   $(TARGET): $(OBJS)
   	$(CC) $(CFLAGS) $(OBJS) -o $@
   
   
   # Ejecuta el programa compilado
   run: $(TARGET)
   	./$(TARGET)
   
   
   # Elimina los archivos generados
   # Borra main.o y hola
   clean:
   	rm -f $(OBJS) $(TARGET)
   
   
   # Limpia y vuelve a compilar
   rebuild: clean all
   ```
