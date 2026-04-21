# MACROS
CC = gcc
CFLAGS = -Wall -Wextra -O2
TARGET = analizador_ips
SRCS = calculadora_ip.c
OBJS = $(SRCS:.c=.o)

.PHONY: all run clean help rebuild

# Objetivo por defecto: compilar el programa
all: $(TARGET)

# Menú de ayuda
help:
	@echo "Objetivos disponibles:"
	@echo "  make         -> compila el programa"
	@echo "  make run     -> compila y ejecuta"
	@echo "  make clean   -> elimina archivos generados"
	@echo "  make rebuild -> limpia y vuelve a compilar"
	@echo ""
	@echo "Importante:"
	@echo "  El archivo ips.txt debe estar en la misma carpeta que el ejecutable"

# Regla patrón:
# Para construir cualquier archivo .o, se necesita su archivo .c con el mismo nombre
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Construye el ejecutable final a partir de los archivos objeto
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

# Ejecuta el programa compilado
run: $(TARGET)
	./$(TARGET)

# Elimina los archivos generados
clean:
	rm -f $(OBJS) $(TARGET)

# Limpia y vuelve a compilar
rebuild: clean all
