#include <iostream>
#include <string>

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

class Animal { // Classe base
    protected:
        string nome;

    public:
        Animal(string _nome) : nome(_nome) {}

        void come() {
            cout << nome << " está a comer." << endl;
        }
        
};

class mamifero : public Animal { // Classe derivada
    protected:
        int numPatas;

    public:
        mamifero(string _nome, int _numPatas) : Animal(_nome) 
        {
            numPatas = _numPatas;
        }

        void anda() {
            cout << nome << " está a caminhar em " << numPatas << " patas." << endl;
        }
};

class gato : public mamifero { // Classe derivada
    public:
        gato(string _nome, int _numPatas) : mamifero(_nome, _numPatas) {}

        void mia() {
            cout << nome << " está a miar." << endl; // Método da classe derivada
        }
};

int main() { // Função principal

    gato meuGato("Loki", 4);

    meuGato.come();
    meuGato.anda();
    meuGato.mia();

    return 0;
}
