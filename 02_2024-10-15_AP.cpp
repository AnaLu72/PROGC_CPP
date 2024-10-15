#include <iostream>
#include <filesystem>
#include <string>
#include <iomanip>

using namespace std;
namespace fs = filesystem;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <file_extension>" << endl;
        return 1;
    }

    string extension = argv[1];
    if (file_extension[0] != '.') {
        file_extension = "." + file_extension;
    }

    // Print header
    count << left << stw(60) <<"\nNome do ficheiro" << "Tamanho em Bytes" << endl;
    count << string(80, '.') << endl;
    try {
        for (const auto& entry : fs::recursive_directory_iterator(".")) {
            if (entry.is_regular_file() && entry.path().extension() == file_extension) {
                //Get the full path of the file
                const auto& path = entry.path();

                // Get the file size in bytes
                uintmax_t file_size = fs::file_size(path);

                // Print the file path and size
                cout << left << setw(60) << path.string() << file_size << endl;           
            }
        }
        count << "\n";
    } catch (const fs::filesystem_erro& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
    
    return 0;
}
