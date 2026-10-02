#include <iostream>
#include <vector>

using namespace std;

class fila_media {
private:
    vector<int> itens;
    // sugestao de atributos; pode/deve haver outros
    int ini = 0,   // posicao do 1o elemento
        tam = 0,   // tamanho (numero atual de elementos)
        cap = 0,   // capacidade (numero max. de elementos)
        soma = 0;

public:
    // construtor receba capacidade; inicializa cap e o vector itens.
    explicit fila_media(int cap) : itens(cap), cap(cap) {  }

    // fila esta cheia?
    bool cheia() const {
        return tam == cap;
    }

    // fila esta vazia?
    bool vazia() const {
        return tam == 0;
    }

    // remove elemento na frente da fila
    void desenfileira() {
        if (vazia()) {
            return;
        }

        soma -= itens[ini];
        ini = (ini + 1) % cap;
        tam--;
    }

    // adiciona i ao final da fila
    void enfileira(int i) {
        if (cheia()) {
            return;
        }

        int final = (ini + tam) % cap;
        itens[final] = i;
        soma += i;
        tam++;
    }

    // retorna elemento na frente da fila
    int proximo() {
        if (vazia()) {
            return -1;
        }
        return itens[ini];
    }

    // retorna atual media dos elementos
    double media() const {
        if (vazia()) {
            return -1;
        }
        return soma/tam;
    }

    // retorna o numero de elementos na fila
    int tamanho() {
        return tam;
    }
};

int main() {
    vector arr = {10, 2, 3, 5, 6, 10, 7, 9, 2, 6, 3, 13, 6};

    fila_media fila(4);

    for (int i : arr) {
        if (fila.cheia()) fila.desenfileira();

        fila.enfileira(i);

        cout << fila.media() << endl;
    }

    // Saida: 10 6 5 5 4 6 7 8 7 6 5 6 7

    return 0;
}
