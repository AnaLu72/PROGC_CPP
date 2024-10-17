#include <iostream>

/**
 * Este conjunto de código mostras definições e utilização do conceito de ponteiros em C/C++.
 * 
 * Todas as variáveis em C/C++ têm associado um endereço de memória.
 * Um ponteiro não é mais do que uma variável que armazena o 'endereço' de memória de outra variável,
 * ou seja, a localização em memória onde essa variável foi guardada.
 * Após atribuição de endereços de memória a variáveis, não é possível alterar os valores desses endereços.
 * Podemos alterar o valor das variáveis, claro, mas não o endereço onde foram armazenadas.
 * Por exemplo, o endereço de memória '0x5f299ffaf0' corresponde à 'morada' da variável 'codPostal'.
 * Se imprimirmos (cout) a variável 'codPostal' teremos o seu valor atual (que poderia ser 5130-021).
 * 
 * Mesmo sem a capacidade de alterar endereços de memória, podemos ter necessidade de utilizá-los o que,
 * efetivamente, certas linguagens como o C++ permitem manipular de forma bastante simples. 
 * Ou seja, conseguimos assim uma flexibilidade na representação de tipo de dados 'abstratos' [ADT - Abstract Data Type],
 * impossível de se obter por outros meios. 
 * Tipos de dados abstratos são, por exemplo, as listas, as filas, as pilhas e as árvores.
 * Na verdade, o conceito de ponteiro surgiu na linguagem Pascal para a implementação de 'listas'.
 * As variáveis do tipo ponteiro 'apontam' para o próximo elemento de uma lista. 
 */
int main() {
    
    /** 
    * O operador '&' é unário e significa 'endereço de...'. Por exemplo, &codPostal quer dizer 'endereço da variável codPostal'.
    * O código abaixo ilustra um exemplo para uma variável do tipo inteiro.
    * Nota: se executarmos o código várias vezes verificamos que o endereço de memória é diferente em cada execução.
    * [Exemplo 01] 
    */
        std::cout << "--- Exemplo 01 --->" << std::endl;
        int numero = 10;
        std::cout << numero  << std::endl;
        std::cout << &numero << std::endl;

/**
 * Vamos considerar que dispomos de um tipo de dados para representar endereços.
 * Chamamos a este tipo "tipo apontador" (Pointer Type).
 * Agora, de alguma forma o compilador tem que saber a que tipo de variável corresponde o endereço.
 * Recordar que um 'char' ocupa 1 byte, um 'int' e um 'float' ocupam 4 byte's, mas com formato diferente
 * e por aí fora. Ou seja, precisamos de saber para que é que aponta o nosso tipo apontador...
 * Para se declarar um ponteiro usamos a sintaxe 'tipo*'. Isto lê-se "apontador de tipo" ou, mais facilmente, 
 * "tipo pointer", e representa um tipo de dados que corresponde a endereços do tipo "tipo"...
 * Por exemplo, 'char*' é um 'char pointer'. Variáveis do tipo 'char*' contêm endereços do tipo 'char'...  
 */

    /** 
    * [Exemplo 02]
    */ 
        std::cout << "--- Exemplo 02 --->" << std::endl;
        int var_ex02 = 20;
        int *ptr_ex02;
        ptr_ex02 = &var_ex02; 
        std::cout << "Mostra o valor atual da variável 'var_ex02': " << var_ex02 << std::endl;
        std::cout << "Mostra o endereço de memória onde se encontra a variável 'var_ex02': " << ptr_ex02 << std::endl;
        std::cout << "Mostra o valor da variável 'var_ex02', apontada pelo ponteiro 'ptr_ex02': " << *ptr_ex02 << std::endl;

    /** 
    * [Exemplo 03]
    */ 
        std::cout << "--- Exemplo 03 --->" << std::endl;
        char letra_ex03 = '-';		
        char *ptr_ex03;
        ptr_ex03 = &letra_ex03;
        /**  
         * Na declaração abaixo, vamos alterar o valor inicial da variável 'letra_ex03' sem efetuarmos qualquer operação de atribuição.
         * Para isso, recorremos ao seu endereço de memória através do ponteiro 'ptr_ex03'.
         * Estamos a dizer "atribui o caráter '+' à posição de memória apontada por...".
         */
        *ptr_ex03 = '+'; 
        std::cout << "Resultado do acesso ao endereço de memória da variável 'letra_ex03': " << letra_ex03 << std::endl;
        
/**
 * Existem alguns erros muito comuns quando se usam ponteiros:
 * 1) não devemos (não podemos!) atribuir um endereço a uma variável que não seja do tipo ponteiro:
 *      int k;  &k = 100;
 * 2) um ponteiro tem que ser sempre inicializado antes de ser usado:
 *      int k;  int *p;    *p = 10; 
 *      Neste último caso, como 'p' não tem um valor conhecido, não se sabe onde será depositado o valor 10.  
 */
    /** 
    * [Exemplo 04]
    */ 
        std::cout << "--- Exemplo 04 --->" << std::endl;
        //int k, *p;
		//*p = 10;
        // std::cout << *p  << std::endl; // Atenção ao erro de 'execução' (runtime).

    /** 
    * [Exemplo 05]
    */ 
        std::cout << "--- Exemplo 05 --->" << std::endl;
        int numeros[5] = {10, 20, 30, 40, 50}; // Definir e inicializar um 'array' de números inteiros.
        for (int i = 0; i < 5; ++i) {
            std::cout << numeros[i] << " ";
        }
        std::cout << std::endl;
        int *ptr = numeros; // Definir e inicializar um 'ponteiro' para o 'array' de números inteiros.
        std::cout << "Endereço de memória onde está o primeiro elemento do 'array': " << ptr << std::endl;
        std::cout << "Valor do primeiro elemento do 'array', usando o índice (index): " << numeros[0] << std::endl;
        std::cout << "Valor do primeiro elemento do 'array', usando o endereço (pointer): " << *ptr << std::endl;
        // Nota: se executarmos o código várias vezes verificamos que os endereços de memória são diferentes em cada execução.
      
    /**
     * Aritmética com ponteiros.
     * O valor de um ponteiro pode ser incrementado (prefix) ou decrementado (postfix).
     * Incrementar um ponteiro significa avançar, para a direita, uma posição de memória (neste caso, dentro do 'array').
     * Decrementar um ponteiro significa retroceder, para a esquerda, uma posição de memória (nesta caso, dentro do 'array').
     * A aritmética de ponteiros não é permitida se o tipo de dados para o qual o ponteiro aponta não estiver completo. 
     * De notar que o operador 'void' é sempre um tipo incompleto.  
     */        
        ptr++; // Incrementar o ponteiro para avançar uma posição de memória (neste caso, dentro do 'array').
        std::cout << "Novo endereço de memória, para onde o ponteiro aponta': " << ptr << std::endl;
        std::cout << "Valor do elemento do 'array', apontado pelo novo endereço:  " << *ptr << std::endl;
        ptr++; // Incrementar mais uma vez o ponteiro para avançar mais uma posição de memória (neste caso, dentro do 'array').
        std::cout << "Novo endereço de memória, para onde o ponteiro aponta': " << ptr << std::endl;
        std::cout << "Valor do elemento do 'array', apontado pelo novo endereço: " << *ptr << std::endl;
        // Nota: verificar que os endereços de memória são sequenciais, de 4 em 4 byte's.
        
        ptr--; // Descrementar o ponteiro para recuar uma posição de memória (neste caso, dentro do 'array').
        std::cout << "Novo endereço de memória, para onde o ponteiro aponta': " << ptr << std::endl;
        std::cout << "Valor do elemento do 'array', apontado pelo novo endereço: " << *ptr << std::endl;

    /** A aritmética de ponteiros pode ser aplicada em instruções mais ou menos complexas. */
        std::cout << "Valor do elemento do 'array', apontado pelo endereço atual: " << *(ptr + 2) << std::endl;

    /** Valores inteiros podem ser adicionados ou subtraídos aos ponteiros e actuam como incremento ou decremento,
     *  respectivamente, mas por um 'número' específico, ao contrário do que sucede nas operações aritméticas.
     *  Também nestes casos o ponteiro deve 'apontar' para um tipo de dados completo.
     */
        ptr += 3; // Incrementar o ponteiro para avançar três posições (e não 3 vezes, como nas somas tradicionais).
        std::cout << "Valor do elemento do 'array', apontado pelo endereço atual: " << *ptr << std::endl;

    /** Para finalizar esta introdução aos ponteiros, devemos sempre ter em atenção as operações de incremento e/ou
     *  decremento que efetuamos. 
     *  Um uso incorreto dos valores dos ponteiros podem remeter-nos para comportamentos inesperados dos nossos programas (no que respeita ao endreçamento de memória).
     */ 

/**
Segundo a IA Claude, temos várias vantagens e desvantagens em usar ponteiros em C/C++. Ora vejam:

Vantagens dos ponteiros:

    1. Gestão eficiente de memória: os ponteiros permitem reservar e libertar memória dinamicamente, o que é útil para estruturas de dados complexas e de tamanho variável;
    2. Melhoria de desempenho: passar ponteiros como argumentos de funções é mais rápido e eficiente do que passar grandes estruturas de dados por valor;
    3. Manipulação de arrays: os ponteiros facilitam a manipulação de arrays, especialmente em operações como ordenação e pesquisa;
    4. Implementação de estruturas de dados: são essenciais para implementar estruturas de dados complexas como listas ligadas, árvores e grafos.
    5. Acesso a hardware: permitem acesso direto a endereços de memória específicos, o que é útil em programação de sistemas e drivers.

Desvantagens dos ponteiros:

    1. Complexidade: a utilização de ponteiros pode tornar o código mais difícil de ler e compreender, especialmente para programadores inexperientes;
    2. Erros de programação: é fácil cometer erros ao manipular ponteiros, como aceder a memória não atribuída ou esquecer de libertar memória, levando a fugas de memória;
    3. Problemas de segurança: o uso incorreto de ponteiros pode levar a vulnerabilidades de segurança, como 'buffer overflow';
    4. Dificuldade na depuração: os erros relacionados com ponteiros podem ser difíceis de detetar e corrigir;
    5. Incompatibilidade entre plataformas: o tamanho dos ponteiros pode variar entre diferentes arquiteturas, o que pode causar problemas de portabilidade;
    6. Overhead de gestão: a gestão manual da memória com ponteiros requer mais atenção e cuidado por parte do programador.
*/

return 0; } // Bug free
