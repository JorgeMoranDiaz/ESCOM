#include <fstream>
#include <iostream>
#include <filesystem>

int main() {
    std::filesystem::create_directories("output");

    std::ofstream file("output/jorge_set.txt");
    if (!file.is_open()) {
        std::cerr << "Error al crear output/jorge_set.txt" << std::endl;
        return 1;
    }

    for (double x = -10.0; x <= 10.0; x += 0.1) {
        double y = x * x;
        file << x << " " << y << std::endl;
    }

    file.close();
    std::cout << "Archivo output/jorge_set.txt generado correctamente." << std::endl;

    return 0;
}
