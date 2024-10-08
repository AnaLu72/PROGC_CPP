//Ana Pereira
//2024-10-08
//UFCD 0810
/*Esta tarefa assíncrona tem como objetivo relembrar a função main(). 
Exatamente, é uma "função" e como tal pode aceitar parâmetros de entrada!
Até hoje não o temos feito, certo?
Mas podemos fazer... 
Vejam, em anexo, uma imagem de exemplo.
Então, escrevam código em C/C++ que mostre a utilização de parâmetros (ou argumentos).
Esses parâmetros devem ser visualizados no tradicional ecrã.
Mas também ser ser guardados num ficheiro de texto.

Submetam o código em C/C++ e o ficheiro de texto criado.*/


#include <stdio.h>

int main(int argc, char *argv[]) {
    // Verifica se há argumentos de entrada
    if (argc < 2) {
        printf("Por favor, forneça argumentos de entrada.\n");
        return 1;
    }

    // Abre o ficheiro para escrita
    FILE *file = fopen("argumentos.txt", "w");
    if (file == NULL) {
        printf("Erro ao abrir o ficheiro.\n");
        return 1;
    }

    // Exibe e guarda os argumentos
    printf("Argumentos fornecidos:\n");
    for (int i = 1; i < argc; i++) {
        printf("%s\n", argv[i]);
        fprintf(file, "%s\n", argv[i]);
    }

    // Fecha o ficheiro
    fclose(file);

    printf("Os argumentos foram guardados no ficheiro 'argumentos.txt'.\n");

    return 0;
}
