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

class Animal {
public:
    string name;

    Animal(string name){
        this -> name = name;
    }

    void Eat() { // Método da classe base
        cout << name << " is eating." << endl;
    }
};

class Dog : public Animal { // Classe derivada
public:
    // Chama o construtor da classe base 'Animal', com o parâmetro 'name'
    Dog(string name) : Animal(name) {}

    void Bark() { // Método da classe derivada
        cout << "au! au!" << endl;
    }
};

int main() {
    
    Dog myDog("Loki"); // Cria um objeto da classe derivada

    // Evoca o método da classe base.
    myDog.Eat();

    // Evoca o método da classe derivada.
    myDog.Bark();

    return 0;
}
