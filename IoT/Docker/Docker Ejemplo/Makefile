#==============================================================================
#CONFIGURACIÓN DE RUTAS
#==============================================================================
CXX      := g++
#Este es nuestro compilador seleccionado g++, puede ser cualquier otro como clang++
CXXFLAGS := -std=c++23 -O3 -Wall
#Aqui colocamos banderas utiles para el compilador

#A partir de esta linea definimos la estructura de nuestro directorio de trabajo:

# Directorios de Código y Herramientas
SRC_DIR     := src
SCRIPT_DIR  := scripts
#Creacion automatica (no existen hasta compilar y ejecutar)
OBJ_DIR     := obj
BIN_DIR     := bin
OUT_DIR     := output

# Archivos de Compilación
#Ejecutable
APP         := $(BIN_DIR)/jorge
SOURCES     := $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS     := $(SOURCES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Archivos de Proceso (Rutas relativas para Gnuplot)
GP_SCRIPT   := $(SCRIPT_DIR)/jorge_set.gp
DATA_FILE   := $(OUT_DIR)/jorge_set.txt
IMAGE_FILE  := $(OUT_DIR)/jorge_set.png

#==============================================================================
#REGLAS DE EJECUCIÓN
#==============================================================================
#Esta es la ejecucion por default de make, es decir si solo escribimos make esto es lo que ejecutaremos por default.
all: prepare $(APP) run plot show_info

#Esta linea es auxiliar y permite a make no confundir reglas con archivos o directorios
.PHONY: all prepare run plot clean show_info

#A parti de este punto definimos las acciones a realizar por make, y que "encadenandolas" nos permite compilar, limpiar, o probar nuestro proyecto

# Crea la estructura de carpetas si no existe
prepare:
	@mkdir -p $(OBJ_DIR) $(BIN_DIR) $(OUT_DIR) $(SCRIPT_DIR)

# Compilación de objetos
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@echo "  [CC]  $< -> $@"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

# Enlazado del binario
$(APP): $(OBJECTS)
	@echo "  [LD]  Creando binario: $@"
	@$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@

# Ejecución del parograma C++
run: $(APP)
	@echo "  [RUN] Generando datos en $(DATA_FILE)..."
	@./$(APP)

# Ejecución de Gnuplot (le pasamos el script desde su carpeta)
plot: $(DATA_FILE)
	@echo "  [GP]  Procesando script: $(GP_SCRIPT)..."
	@gnuplot $(GP_SCRIPT)

show_info:
	@echo "-------------------------------------------------------"
	@echo "✅ Proceso Finalizado."
	@echo "📂 Binario: $(APP)"
	@echo "🖼️  Imagen:  $(IMAGE_FILE)"
	@echo "-------------------------------------------------------"

clean:
	@echo "  [CLEAN] Borrando carpetas generadas..."
	@rm -rf $(OBJ_DIR) $(BIN_DIR) $(OUT_DIR)
