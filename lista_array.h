//
// Created by IFPE on 10/06/2025.
//

#ifndef FILAS_LISTA_H
#define FILAS_LISTA_H

#include <vector>
#include "lista.h"

using namespace std;

// Lista indexada em 1
// T é o tipo do dado, ex., tarefa
template <class T>
class ListaArray : public Lista<T> {
protected:
    int num_itens = 0;
    vector<T> itens;

    T & pegar_ref(int idx) {
        if (idx <= 0 || idx > tamanho()) throw runtime_error("Indice invalido");

        return itens[idx - 1];
    }

public:
    explicit ListaArray(int cap)  : Lista<T>(cap), itens(cap) {
    }

    ~ListaArray() override = default;

    void adicionar(T v) override {
        if (num_itens >= this->capacidade) throw runtime_error("Lista cheia!");

        itens[num_itens] = v;
        num_itens++;
    }

    // Indexado de 1..tamanho
    void inserir(int idx, T v) override {
        if (num_itens >= this->capacidade) throw runtime_error("Lista cheia!");
        if (idx < 1 || idx > tamanho()) throw runtime_error("Indice invalido");
        
        for (int i = num_itens; i >= idx; i--) {
            itens[i + 1] = itens[i];
        }

        itens[idx - 1] = v;
        
        num_itens++;
    }

    // Indexado de 1..tamanho
    void remover(int idx) override {
        if (idx < 1 || idx > tamanho()) throw runtime_error("Indice invalido");

        for (int i = idx; i < num_itens; i++) {
            itens[i-1] = itens[i];
        }

       
        num_itens--;
    }

    int tamanho() const override {
        return num_itens;
    }

    T pegar(int idx) const override {
        if (idx < 1 || idx > tamanho()) throw runtime_error("Indice invalido");

        return itens[idx - 1];
    }

    int buscar(T valor) const override {
        for (int i = 0; i < num_itens; i++) {
            if (itens[i] == valor) {
                return (i + 1);
            }
        }
        return -1;
    }

    T & operator [] (int idx) override {
        return pegar_ref(idx);
    }

};


#endif //FILAS_LISTA_H
