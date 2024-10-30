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
class umaClasse {
public:
    int valor;
    
    // Construtor por omissão [by default] (sem parâmetros)
    umaClasse() {
        cout << "Evoca o construtor sem parâmetros." << endl;
        valor = 29;
    }

    // Construtor com parâmetros
    umaClasse(int umValor) {
        cout << "Evoca o construtor com um parâmetro (ou argumento)." << endl;
        valor = umValor;
    }

    // Método para mostrar o valor
    void mostraValor() {
        cout << "valor: " << valor << endl;
    }

};

// Função principal
int main() {
    meuCarimbo();
    mudaLinha();
    umaClasse objeto_um;       
       objeto_um.mostraValor(); // valor: 29

    umaClasse objeto_dois(10); // Evoca o construtor com um parâmetro (ou argumento).
       objeto_dois.mostraValor();

    return 0;
}