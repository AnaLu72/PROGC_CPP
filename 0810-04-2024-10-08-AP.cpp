//UFCD 0810
//Ana Pereira
//2024-10-08
/*Nesta tarefa assíncrona devem resolver o seguinte exercício (em C++): 
"Faça um programa que coloque "Olá Mundo!" em bom português (com acentos), e que indique
o tamanho em bytes (operador sizeof) dos seguintes tipos de dados: char; short; int; long;
long long; float; double; long double".
O programa deve guardar os resultados num ficheiro de texto
Submetam o código em C++ e o ficheiro de texto criado.*/

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    // Imprimir a mensagem "Olá Mundo!"
    cout << "Olá Mundo!" << endl;

    // Abrir um arquivo de texto para escrita
    ofstream arquivo("tamanhos_tipos.txt");

    // Calcular e escrever os tamanhos dos tipos de dados
    arquivo << "Tamanho do tipo char: " << sizeof(char) << " bytes" << endl;
    arquivo << "Tamanho do tipo short: " << sizeof(short) << " bytes" << endl;
    arquivo << "Tamanho do tipo int: " << sizeof(int) << " bytes" << endl;
    arquivo << "Tamanho do tipo long: " << sizeof(long) << " bytes" << endl;
    arquivo << "Tamanho do tipo long long: " << sizeof(long long) << " bytes" << endl;
    arquivo << "Tamanho do tipo float: " << sizeof(float) << " bytes" << endl;
    arquivo << "Tamanho do tipo double: " << sizeof(double) << " bytes" << endl;
    arquivo << "Tamanho do tipo long double: " << sizeof(long double) << " bytes" << endl;

    // Fechar o arquivo
    arquivo.close();

    cout << "Os tamanhos dos tipos de dados foram escritos no arquivo tamanhos_tipos.txt" << endl;

    return 0;
}