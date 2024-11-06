#include <iostream> // Para trabalhar com entrada e saída
#include <string> // Para trabalhar com strings
#include <ctime> // Para trabalhar com datas e horas
#include <fstream> // Para trabalhar com arquivos


// Para evitar o uso de 'std::'
using namespace std; 

// Função para mudar de linha
void mudaLinha(void) 
{
    printf("\n"); // muda de linha
} 

// Função para adicionar um carimbo de data e hora
void meuCarimbo(void) 
{
    time_t tempo_atual = time(NULL);
    struct tm *tempo_local = localtime(&tempo_atual);
    char data_hora[64];
   
    strftime(data_hora, sizeof(data_hora), "%d-%m-%Y %H:%M:%S", tempo_local);
    printf("\n[Ana Pereira] - [ %s ]", data_hora);
}

// Classe base Funcionario
class Funcionario {
protected:
    string nome;
    string numeroContribuinte;
public:
    Funcionario(string n, string nc) : nome(n), numeroContribuinte(nc) {}
    virtual void mostrarDetalhes() const = 0; // Método virtual puro
    virtual ~Funcionario() {}
};

// Classe derivada Interno
class Interno : public Funcionario {
private:
    float salarioBase;
    float bonusAnual;
    string projeto;
public:
    Interno(string n, string nc, float sb, float ba, string p)
        : Funcionario(n, nc), salarioBase(sb), bonusAnual(ba), projeto(p) {}

    void mostrarDetalhes() const override {
        cout << "Interno: " << nome << endl;
        cout << "Numero de Contribuinte: " << numeroContribuinte << endl;
        cout << "Salario Base: €" << salarioBase << endl;
        cout << "Bonus Anual: €" << bonusAnual << endl;
        cout << "Projeto: " << projeto << endl;
    }
};

// Classe derivada Freelancer
class Freelancer : public Funcionario {
private:
    int horasTrabalhadas;
    float valorPorHora;
    string turno;
public:
    Freelancer(string n, string nc, int ht, float vph, string t)
        : Funcionario(n, nc), horasTrabalhadas(ht), valorPorHora(vph), turno(t) {}

    void mostrarDetalhes() const override {
        cout << "Freelancer: " << nome << endl;
        cout << "Numero de Contribuinte: " << numeroContribuinte << endl;
        cout << "Horas Trabalhadas: " << horasTrabalhadas << endl;
        cout << "Valor por Hora: €" << valorPorHora << endl;
        cout << "Turno: " << turno << endl;
    }
};

int main() {
    meuCarimbo();
    mudaLinha();
    
    // Criação de instâncias de cada classe
    Interno interno1("Joao Silva", "123456789", 1500.0, 200.0, "Projeto A");
    Freelancer freelancer1("Ana Pereira", "987654321", 100, 15.0, "Noite");

    // Mostrar detalhes de cada funcionário
    interno1.mostrarDetalhes();
    cout << endl;
    freelancer1.mostrarDetalhes();

    return 0;
}
