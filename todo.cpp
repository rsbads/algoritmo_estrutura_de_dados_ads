//
// Created by IFPE on 05/05/2026.
//

#include <iostream>
#include <list>
#include <map>
#include <string>
#include <vector>

using namespace std;

enum Comando {
    UNKNOWN,
    ADD,
    INS,
    DELETE,
    NEXT,
    PREV,
    SHOW,
    LIST,
    QUIT
};
// Explicado no futuro
std::map<string, Comando> comandos = {
    {"add", ADD},
    {"ins", INS},
    {"del", DELETE},
    {"next", NEXT},
    {"prev", PREV},
    {"show", SHOW},
    {"list", LIST},
    {"quit", QUIT}
};

int main() {
    vector tarefas = {
        "Pratica de Redes",
        "Questionario de AED",
        "Estudar Listas",
        "Pesquisar sobre a STL",
        "Instalar IDE"
    };

    list<string> todo;
    for (auto &s : tarefas) todo.push_back(s);

    string cmd, tarefa;

    // iterador que aponta para tarefa atual (1a)
    auto atual = todo.begin();

    while (cout << endl << "Comando: " && cin >> cmd && cmd != "quit") {
        switch (comandos[cmd]) {
            case ADD:
                cout << "Nova tarefa a adicionar:";
                cin.ignore();
                getline(cin, tarefa);
                todo.push_back(tarefa);
                break;
            case INS:
                cout << "Nova tarefa a inserir:";
                cin.ignore();
                getline(cin, tarefa);
                atual = todo.insert(atual, tarefa);
                break;
            case DELETE:
                if (todo.empty()) {
                    cout << "Nao ha tarefas para apagar!" << endl;
                    break;
                }
                atual = todo.erase(atual);
                if (atual == todo.end() && !todo.empty()) --atual;
                break;
            case NEXT:
                if (todo.empty() || next(atual) == todo.end()) {
                    cout << "Erro: ja esta na ultima tarefa!" << endl;
                    break;
                }
                ++atual;
                cout << "Tarefa atual: " << *atual << endl;
                break;
            case PREV:
                if (todo.empty() || atual == todo.begin()) {
                    cout << "Erro: ja esta na primeira tarefa!" << endl;
                    break;
                }
                --atual;
                cout << "Tarefa atual: " << *atual << endl;
                break;
            case SHOW:
                if (todo.empty()) {
                    cout << "Nao ha tarefas!" << endl;
                    break;
                }
                cout << "Tarefa atual: " << *atual << endl;
                break;
            case LIST:
                cout << "Tarefas: " << endl;
                for (auto &t : todo)
                    cout << " - " << t << endl;
                break;
            case UNKNOWN:
            default:
                cout << "Commando desconhecido! (quit para sair)" << endl;
        }
    }
}