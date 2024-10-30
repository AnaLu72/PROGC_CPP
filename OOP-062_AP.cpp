#include <iostream>

using namespace std; // Para evitar o uso de 'std::'

void mudaLinha(void) // Função para mudar de linha
{
    printf("\n"); // muda de linha
} 

void meuCarimbo(void) // Função para adicionar um carimbo de data e hora
{
    time_t tempo_atual = time(NULL);
    struct tm *tempo_local = localtime(&tempo_atual);
    char data_hora[64];
   
    strftime(data_hora, sizeof(data_hora), "%d-%m-%Y %H:%M:%S", tempo_local);
    printf("\n[Ana Pereira] - [ %s ]", data_hora);
}

// Definição da classe
class Carro {
public:
    string nomeCarro;

    // Construtor com um argumento
    Carro(string nomeCarro) {
        this -> nomeCarro = nomeCarro;
    }

    // Construtor de cópia
    Carro(Carro& outroCarro) {
        nomeCarro = outroCarro.nomeCarro;
    }
};

// Função principal
int main() {
    meuCarimbo();
    mudaLinha();
    Carro carroOriginal("Ruído tipo Mustang"); 
    cout << "Carro original: " << carroOriginal.nomeCarro << endl;

    Carro carroCopiado(carroOriginal);
    cout << "Carro copiado: " << carroCopiado.nomeCarro << endl;

    Carro outroCarro(carroCopiado);
    cout << "Outro carro: " << outroCarro.nomeCarro << endl;

    return 0;
}