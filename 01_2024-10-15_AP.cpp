#include <iostream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

/**
 * Iterates over all files in the current directory and prints the filename
 * of each regular file that matches the specified file extension.
 *
 * @param argc The number of command-line arguments, including the program name.
 * @param argv An array of C-style strings containing the command-line arguments.
 * @return 0 on successful completion, 1 on error.
 */
int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << "<file_extention>" << std::endl;
        return 1;
    }

    //Este código adiciona o 'ponto' à extensão do ficheiro.
    std::string extension = argv[1];
    if (extension[0] != '.') {
        extension = "." + extension;
    }

    /// Iterates over all files in the current directory and prints the filename
    /// of each regular file that matches the specified file extension.
    for (const auto& entry : fs::directory_iterator(".")) {
        if (entry.is_regular_file() && entry.path().extension() == extension) {
            std::cout << entry.path().filename() << std::endl;
        }
    }

    return 0;
}