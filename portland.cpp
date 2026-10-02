#include <iostream>
#include <vector>

using namespace std;

void portland(const vector<vector<int>> &M) {
    int n = M.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            int cameras = M[i][j] + M[i][j + 1] + M[i + 1][j] + M[i + 1][j + 1];

            if (cameras >= 2)
                cout << 's';
            else {
                cout << 'u';
            }
        }
        cout << endl;
    }
}

int main() {
    // vector<vector<int>> M(n, vector<int>(n));
    const vector<vector<int>> M1 = {{1, 0},
                                    {0, 0}};
    const vector<vector<int>> M2 = {{1, 0, 0},
                                    {1, 1, 0},
                                    {0, 0, 1}};
    const vector<vector<int>> M3 = {{1, 1, 0, 1},
                                    {1, 0, 1, 0},
                                    {1, 0, 0, 1},
                                    {0, 1, 1, 0}};

    cout << "Caso 1:" << endl;
    portland(M1);
    cout << "Caso 2:" << endl;
    portland(M2);
    cout << "Caso 3:" << endl;
    portland(M3);
    return 0;
}