#include <iostream>
#include <vector>

using namespace std;

void solucao_iterativa(vector<string> &mat) {
    bool changed;
    const int M = static_cast<int>(mat.size()); // # linhas
    const int N = static_cast<int>(mat[0].size()); // # colunas
    do {
        changed = false;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (mat[i][j] != '.') continue;

                if ((i > 0 && mat[i - 1][j] == 'o') ||
                    // (j > 0 && i < M - 1 && mat[i][j - 1] == 'o' && mat[i + 1][j - 1] == '#') ||
                    (j < N - 1 && i < M - 1 && mat[i][j + 1] == 'o' && mat[i + 1][j + 1] == '#')) {
                    mat[i][j] = 'o';
                    changed = true;
                }
            }
        }
    }
    while (changed);
}

void recursao(vector<string> &mat, int i, int j) {
    const int M = static_cast<int>(mat.size()); // # linhas
    const int N = static_cast<int>(mat[0].size()); // # colunas

    // dentro dos limites?
    if (i < 0 || i >= M || j < 0 || j >= N) return;

    if (mat[i][j] != '.') return;

    if ((i > 0 && mat[i - 1][j] == 'o') ||
        (j > 0 && i < M - 1 && mat[i][j - 1] == 'o' && mat[i + 1][j - 1] == '#')
        //(j < N - 1 && i < M - 1 && mat[i][j + 1] == 'o' && mat[i + 1][j + 1] == '#')
        ) {

        mat[i][j] = 'o';

        recursao(mat, i, j - 1);
        recursao(mat, i, j  + 1);
        recursao(mat, i + 1, j);
    }
}

void solucao_recursiva(vector<string> &C) {
    for (int j = 0; j < C[0].size(); j++) {
        if (C[0][j] == 'o') {
            recursao(C, 0, j - 1);
            recursao(C,0, j  + 1);
            recursao(C, 1, j);
            return;
        }
    }
}

void print(vector<string> &C) {
    for (int i = 0; i < C.size(); i++) {
        for (int j = 0; j < C[i].size(); j++) {
            cout << C[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    // vector<string> matriz = {
    //     "..o",
    //     ".#.",
    //     "..."
    // };

    // vector<string> matriz = {
    //     ".o...",
    //     ".#...",
    //     ".....",
    //     ".....",
    //     ".....",
    //     "..#..",
    //     "....."
    // };
    //
    vector<string> matriz = {
        ".......o......",
        ".###...####.#.",
        "..............",
        "..######......",
        "..............",
        ".#.####....##.",
        "..............",
        ".....####.....",
        ".............."
    };

    auto m_iterativa = matriz;
    auto m_recursiva = matriz;

    solucao_iterativa(m_iterativa);
    solucao_recursiva(m_recursiva);

    cout << "Original: " << endl;
    print(matriz);
    cout << "Iterativa: " << endl;
    print(m_iterativa);
    cout << "Recursiva: " << endl;
    print(m_recursiva);

    return 0;
}