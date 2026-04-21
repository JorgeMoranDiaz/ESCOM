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
