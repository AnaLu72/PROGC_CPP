// Estruturar o código
// Compilar e executar
// Corrigir erros 

#include <iostream>
#include <cstdio> 
#include <ctime>

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

class Retangulo {
    int altura;
    int largura;

public:
    // Construtor.
    Retangulo(int alt, int larg) : altura(alt), largura(larg) {}

    // Método para desenhar o retângulo.
    void desenha();
    void desenha(char c);
}; // Fim de class Retangulo.


// Construtor. O consrtutor deve ser implementado na classe base, public ou private.
// Retangulo::Retangulo(int alt, int larg) : altura(alt), largura(larg){} // Fim de Retangulo::Retangulo()

// Implementação do método que desenha o retângulo com o caractere '*'
void Retangulo::desenha() { 
    // Desenha o retângulo preenchendo-o com o caractere '*'
    for(int i = 0; i < altura; i++) {
        for(int j = 0; j < largura; j++) 
            cout << '*';
        cout << "\n";
        } // Fim de for(int i = 0...
} // Fim de Retangulo::desenha()

// Implementação do método que desenha o retângulo com o caractere c recebido como argumento.
void Retangulo::desenha(char c) { 
    for(int i = 0; i < altura; i++) {
        for(int j = 0; j < largura; j++)
            cout << c;
        cout << "\n";
        } // Fim de for(int i = 0...
    } // Fim de Retangulo::desenha(char c)

int main() { 
    meuCarimbo();
    mudaLinha();

    // Cria um objeto da classe Retangulo.
    Retangulo ret(8, 12);

    // Desenha usando as duas versões de desenha()
    ret.desenha();
    cout << "\n\n";
    ret.desenha('A');
    cout << "\n\n";
return 0;
} // Fim de main()
//---------------------------------------------------------