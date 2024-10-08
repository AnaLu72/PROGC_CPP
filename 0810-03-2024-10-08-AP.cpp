//UFCD_0810-03-2024-10-08-AP.cpp
//Ana Pereira
//2024-10-08
/*"Pretende-se um programa que leia as horas, minutos e segundos introduzidas pelo utilizador, e calcule o número total de segundos que passaram desde o início do dia, ou seja, desde as 00:00h".
O programa deve efetuar uma validação aos valores introduzidos:
a hora não pode ser superior a 23 nem inferior a 1;
os minutos não podem ser superiores a 60 nem inferiores a 0;
os segundos não podem ser superiores a 60 nem inferiores a 0;
o valor total de segundos deve ser guardado num ficheiro de texto.*/

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    int horas, minutos, segundos;

    // Leitura das horas, minutos e segundos
    cout << "Introduza as horas (1-23): ";
    cin >> horas;
    if (horas < 1 || horas > 23) {
        cout << "Horas inválidas!" << endl;
        return 1;
    }

    cout << "Introduza os minutos (0-60): ";
    cin >> minutos;
    if (minutos < 0 || minutos > 60) {
        cout << "Minutos inválidos!" << endl;
        return 1;
    }

    cout << "Introduza os segundos (0-60): ";
    cin >> segundos;
    if (segundos < 0 || segundos > 60) {
        cout << "Segundos inválidos!" << endl;
        return 1;
    }

    // Cálculo do total de segundos
    int totalSegundos = horas * 3600 + minutos * 60 + segundos;

    // Gravação do resultado num ficheiro de texto
    ofstream outFile("total_segundos.txt");
    if (outFile.is_open()) {
        outFile << "Total de segundos desde o início do dia: " << totalSegundos << endl;
        outFile.close();
        cout << "Resultado guardado em 'total_segundos.txt'" << endl;
    } else {
        cout << "Erro ao abrir o ficheiro!" << endl;
        return 1;
    }

    return 0;
}
