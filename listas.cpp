#include <iostream>

#include "lista_array.h"
#include "lista_encadeada.h"

using namespace std;

void teste_inteiros(Lista<int> &lista) {
    cout << " --- Teste com Inteiros --- " << endl << endl;

    vector valores = {11, 4, 7, 9, 10};

    for (auto &v : valores) {
        lista.adicionar(v);
    }

    cout << "ANTES: " << endl;
    for (int i = 1; i <= lista.tamanho(); i++) {
        cout << " " << i << ": " << lista.pegar(i) << endl;
    }
    cout << endl;

    lista[5] = 55;
    lista.inserir(2, 22);
    lista.remover(3);
    lista.adicionar(77);
    lista.remover(4);

    cout << "DEPOIS: " << endl;
    for (int i = 1; i <= lista.tamanho(); i++) {
        cout << " " << i << ": " << lista.pegar(i) << endl;
    }
    cout << endl;

    vector b = {10, 22, 11, 5, 7};
    cout << "BUSCAS: " << endl;
    for (auto v : b) {
        cout << "- Buscando " << v << ": " << lista.buscar(v) << endl;
    }
}

void teste_strings(Lista<string> &lista) {
    cout << endl << " --- Teste com Strings --- " << endl << endl;

    string nomes[] = {
        "Felipe", "Antonio", "Esmeralda","Frederico", "Matilde"
    };

    for (const auto & nome : nomes) {
        lista.adicionar(nome);
    }

    cout << "ANTES: " << endl;
    for (int i = 1; i <= lista.tamanho(); i++) {
        cout << i << ": " << lista.pegar(i) << endl;
    }

    lista.remover(1);
    lista.inserir(2, "Josias");
    lista.remover(3);
    lista[3] = "Geraldo";

    cout << endl << "DEPOIS: " << endl;
    for (int i = 1; i <= lista.tamanho(); i++) {
        cout << i << ": " << lista.pegar(i) << endl;
    }

    vector b = {"Matilde", "Maria", "Pedro", "Carlos", "Josias"};
    cout << endl << "BUSCAS: " << endl;
    for (auto v : b) {
        cout << "- Buscando " << v << ": " << lista.buscar(v) << endl;
    }
}

int main() {
    cout << endl << " === Testando Lista Array ==== " << endl << endl;

    ListaArray<int> lista_arr_int(10);
    ListaArray<string> lista_arr_str(10);

    teste_inteiros(lista_arr_int);
    teste_strings(lista_arr_str);

    cout << endl << " === Testando Lista Encadeada ==== " << endl << endl;

    ListaEncadeada<int> lista_enc_int(10);
    ListaEncadeada<string> lista_enc_str(10);

    teste_inteiros(lista_enc_int);
    teste_strings(lista_enc_str);


    return 0;
}
