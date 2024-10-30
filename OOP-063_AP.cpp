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

class classBase {
public:
    int comissão = 10;
    void print() {
        cout << "Função principal." << endl;
    }
};

class classDerivada : public classBase {
public:
    void print() {
        cout << "Função derivada." << endl;
    }
};

int main() {
    meuCarimbo();
    mudaLinha();

    classDerivada exemploUm;

    exemploUm.print();
    
    cout << "exemploUm.comissao" << endl;
    
    return 0;
}