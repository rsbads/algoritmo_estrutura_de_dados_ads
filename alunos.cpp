//
// Created by IFPE on 05/05/2026.
//

#include <string>
#include "lista_array.h"
#include "lista_encadeada.h"

using namespace std;

struct Aluno {
    string nome;
    float nota;

    // Necessario definir por conta das buscas
    bool operator==(const Aluno&a) const {
        return a.nome == nome && a.nota == nota;
    }
};

void filtrar(Lista<Aluno> &alunos, Lista<Aluno> &reprovados, float nota) {
    vector<int> indices_reprovados;

    for (int i = 1; i <= alunos.tamanho(); i++) {
        if (alunos.pegar(i).nota < nota) {
            reprovados.adicionar(alunos.pegar(i));
            indices_reprovados.push_back(i);
        }
    }

    int total_reprovados = indices_reprovados.size();

    for (int i = total_reprovados - 1; i >= 0; i--) {
        alunos.remover(indices_reprovados[i]);
    }
}

int main() {
    // ListaArray<Aluno> alunos(10);
    // ListaArray<Aluno> reprovados(10);
    ListaEncadeada<Aluno> alunos(10);
    ListaEncadeada<Aluno> reprovados(10);

    vector<Aluno> todos = {
        {"Esmeralda", 7.5},
        {"Vicente", 8.6},
        {"Gilmar", 5.4},
        {"Matilda", 4.6},
        {"Vitruvio", 9.6},
        {"Roberval", 6.8},
        {"Tereza", 8.2},
        {"Juliete", 5.5}
    };

    for (auto &a : todos) alunos.adicionar(a);

    filtrar(alunos, reprovados, 7.0);

    cout << "Alunos aprovados: " << endl;
    for (int i = 1; i <= alunos.tamanho(); i++) {
        const auto &[nome, nota] = alunos[i];
        cout << "- " << nome << ": " << nota << endl;
    }

    cout << endl;
    cout << "Alunos reprovados: " << endl;
    for (int i = 1; i <= reprovados.tamanho(); i++) {
        const auto &[nome, nota] = reprovados[i];
        cout << "- " << nome << ": " << nota << endl;
    }
}