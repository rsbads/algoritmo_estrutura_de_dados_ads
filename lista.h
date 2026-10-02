//
// Created by IFPE on 05/05/2026.
//

#ifndef PRATICA_04_LISTA_H
#define PRATICA_04_LISTA_H

#include <stdexcept>

template <class T>
class Lista {
protected:
    int capacidade;

public:
    explicit Lista(int cap) : capacidade(cap) {
        if (capacidade <= 0) throw std::runtime_error("Capacidade invalida");
    }
    virtual ~Lista() = default;

    virtual void adicionar(T v) = 0;
    // Indexado de 1..tamanho
    virtual void inserir(int idx, T v) = 0;
    virtual void remover(int idx) = 0;
    virtual T    pegar(int idx) const = 0;
    virtual int buscar(T valor) const = 0;
    virtual int tamanho() const = 0;

    virtual T & operator [] (int idx) = 0;
};

#endif //PRATICA_04_LISTA_H