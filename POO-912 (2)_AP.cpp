// Ana Pereira - 2024-11-06
// UFCD 0810 - Programação Orientada a Objetos
// POO-912_AP.cpp

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

// Classe base
class Date {
private:
   int dia;
   int mes;
   int ano;
public:
   Date(int d = 0, int m = 0, int a = 0) : dia(d), mes(m), ano(a) {}

   void imprimir() const{
      printf("%02d-%02d-%04d", dia, mes, ano);
   }
};

// Classe derivada para alugar DVD
class DVD {
private:
   float preco;
   string titulo;
public:
   DVD(float p = 0.0f,  string t = "") : preco(p), titulo(t) {}
  
   virtual void adquirir() = 0; // Método virtual para imprimir detalhes do DVD
   virtual void devolver() = 0;
   virtual void recibo() = 0;

   float getPreco() const {
      return preco;
   }

   string getTitulo() const {
      return titulo;
   }
};

// Classe derivada para vender DVD
class DVDdeVender : public DVD {
public:
  DVDdeVender(string t = "", float p = 0.0f) : DVD(p, t) {}
  
   void adquirir() override {
      cout << "Adquirir DVD para vender: " << getTitulo() << " por €" <<getPreco() << endl;
   }
   void devolver() override {
      cout << "Devolver DVD de venda." <<  getTitulo() << endl;
   }
   void recibo() override {
      cout << "DVD vendido: " <<getTitulo() << " por €" << getPreco() << endl;
   }
};

// Classe derivada para alugar DVD
class DVDdeAlugar : public DVD {
private:
   Date dataDevolucao;
public:
  DVDdeAlugar(string t = "", float p = 0.0f, Date d = Date()) : DVD(p, t), dataDevolucao(d) {}
   void adquirir() override {
      cout << "Adquirir DVD para alugar: " << getTitulo() << " por €" << getPreco() << endl;
   }
   void devolver() override {
      cout << "Devolver DVD de alugar." << getTitulo() << endl;
   }
   void recibo() override {
      cout << "DVD alugado: " << getTitulo() << " por €" << getPreco() << ", Data de Devolução: ";
      dataDevolucao.imprimir();
      cout << endl;
   }
};

/// Classe derivada para emprestar DVD
class ColecaoDeDVDs {
private:
   DVD* dvds[100]; // Array de ponteiros para DVDs
   int numeroDVDs; 
public:
   ColecaoDeDVDs() : numeroDVDs(0) {}

   // Função para adicionar um DVD
   void acrescentarDVD(DVD* d) {
      if (numeroDVDs < 100) { // Se ainda tem espaço no array
         dvds[numeroDVDs++] = d; // Acrescenta o DVD ao array
      } else {
         cout << "Não há espaço para adicionar mais DVDs." << endl;
      }   
   }

   // Função para imprimir o relatório
   void relatorio() {
      for (int i=0; i < numeroDVDs; i++) { // Para cada DVD
         dvds[i]->recibo(); // Imprime os detalhes do DVD
      }
   }

   // Destrutor da classe
   ~ColecaoDeDVDs() { 
      for (int i = 0; i < numeroDVDs; ++i) {
          delete dvds[i];
      } 
   }
};

// Função principal
int main() {
   meuCarimbo();
   mudaLinha();

    // Cria um DVD de venda
   ColecaoDeDVDs c;
   
   c.acrescentarDVD(new DVDdeAlugar("Matrix", 10.0, Date(20, 1, 2022)));
   c.acrescentarDVD(new DVDdeVender("Star Wars", 15.0));
   c.relatorio();
   
   return 0;
}