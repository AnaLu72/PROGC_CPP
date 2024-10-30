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

// Classe base
class Livro {
protected: // Acesso protegido
    int paginas;

public: // Acesso público
    Livro(int p) : paginas(p) {} // Construtor
    virtual void descreve() { // Método virtual - permite que o método apropriado seja 
    //chamado com base no tipo do objeto apontado pelo ponteiro da classe base.
        cout << "Este livro tem " << paginas << " paginas." << endl;
    }
};

// Classe derivada
class LivroPonto : public Livro {
private:
    int sumarios;
public:
    LivroPonto(int pag, int sum) : Livro(pag), sumarios(sum) {}
    void descreve() override { //override indica que o método substitui o método da classe base. Para deixar 
    //claro que as funções desenha nas classes derivadas estão sobreescrevendo a função virtual na classe base.
        cout << "Este livro de sumarios tem " << paginas << " paginas e " << sumarios << " sumarios." << endl;
    }
};

// Classe derivada
class Dicionario : public Livro { // Classe derivada
private: // Acesso privado
    int entradas;

public:
    Dicionario(int pag, int ent) : Livro(pag), entradas(ent) {}
    void descreve() override {
        cout << "Este dicionario tem " << paginas << " paginas e " << entradas << " entradas." << endl;
    }
};

// Função para imprimir o tipo do objeto apontado pelo ponteiro da classe base
int main() { 
    meuCarimbo();
    mudaLinha();

    // Criar objetos e adicionar à tabela
    Livro* tabela[5]; // Tabela de ponteiros para objetos Livro
    tabela[0] = new Livro(100); // Cria um objeto Livro
    tabela[1] = new Dicionario(900, 10000); // Cria um objeto Dicionario
    tabela[2] = new LivroPonto(100, 9); // Cria um objeto LivroPonto
    tabela[3] = new Dicionario(700, 5000); 
    tabela[4] = new Livro(250);

    // Chamar o método descreve() para cada objeto na tabela
    for (int i = 0; i < 5; i++) { // Loop para percorrer a tabela e chamar o método descreve()
        tabela[i]->descreve();
    }

    // Deletar objetos alocados dinamicamente para evitar vazamento de memória
    for (int i = 0; i < 5; i++) { // Loop para percorrer a tabela e deletar objetos
        delete tabela[i];
    }

    return 0;
}


