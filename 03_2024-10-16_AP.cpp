// Autor: Ana Pereira
// Data: 16/10/2024
// Descrição: Este programa demonstra o uso de ponteiros em C.


#include <stdio.h>
#include <time.h>

// Protótipos das funções
void mudaLinha(void);
void meuCarimbo(void);

int main() {
    meuCarimbo(); // Mostra as informações do programa
    mudaLinha();  // Separa visualmente as seções

    // O meu programa começa aqui...

    int numeros[5] = {10, 20, 30, 40, 50}; // Declara um array de inteiros com 5 elementos
    int *ptr = numeros; // Declara um ponteiro para o primeiro elemento do array

    printf("Primeiro elemento: %d\n", numeros[0]); // Imprime o valor do primeiro elemento do array
    printf("Valor apontado pelo ponteiro: %d\n", *ptr); // Imprime o valor apontado pelo ponteiro (o primeiro elemento do array)

    ptr++; // Avança o ponteiro para o próximo elemento do array
    printf("Valor após avançar o ponteiro: %d\n", *ptr); // Imprime o valor do elemento atual

    ptr--; // Retrocede o ponteiro para o elemento anterior
    printf("Valor após retroceder o ponteiro: %d\n", *ptr); // Imprime o valor do elemento atual

    printf("Terceiro elemento (usando ponteiro): %d\n", *(ptr + 2)); // Imprime o valor do terceiro elemento do array usando aritmética de ponteiros

    // O meu programa termina aqui...

    mudaLinha();  // Separa visualmente as seções
    meuCarimbo(); // Mostra as informações do programa novamente

    return 0;
}

// ------------------------------------------
// Função que muda de linha quando necessário
void mudaLinha(void) {
    printf("\n"); // Muda de linha
}

// ------------------------------------------
// Função que mostra (algumas) informações gerais
void meuCarimbo(void) {
    time_t tempo_atual = time(NULL); // Obtém o tempo atual
    struct tm *tempo_local = localtime(&tempo_atual); // Converte o tempo atual para o horário local
    char data_hora[64]; // Buffer para armazenar data e hora
    strftime(data_hora, sizeof(data_hora), "%d-%m-%Y %H:%M:%S", tempo_local); // Formata a data e hora
    printf("\n[Ana Pereira] - [ %s ]", data_hora); // Imprime a data e hora formatadas
    mudaLinha(); // Muda de linha
}