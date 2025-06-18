#include <iostream>
#include <vector>
#include <cstdlib>
#include <unistd.h>
#include <ctime>

using namespace std;

int main() {
    const int largura = 80;
    const int altura = 30;
    const string caracteres = "0abcdefghijklmnopqrstuvz12345678901";

    vector<int> coluna(largura, 0);

    srand(time(0));

    while (true) {
        for (int y = 0; y < altura; y++) {
            for (int x = 0; x < largura; x++) {
                if (coluna[x] == y) {
                    cout << caracteres[rand() % caracteres.length()];
                } else if (coluna[x] - y < 5 && coluna[x] - y > 0) {
                    cout << ".";
                } else {
                    cout << " ";
                }
            }
            cout << endl;
        }

        for (int i = 0; i < largura; i++) {
            if (coluna[i] > altura + rand() % 10) {
                if (rand() % 100 > 90) {
                    coluna[i] = 0;
                }
            } else {
                coluna[i]++;
            }
        }

        usleep(80000);
        system("clear");
    }

    return 0;
} 
