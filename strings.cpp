#include <iostream>
#include <vector>

using namespace std;

string reordenar(const string &str) {

    vector<int> contador(26, 0);
    for (char c : str) {
        contador[c - 'a']++;
    }

    string resultado = "";
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < contador[i]; j++) {
            resultado += char('a'+ i);
        }
    }


    return resultado;
}

int main() {
    cout << reordenar(string("casa")) << endl;
    cout << reordenar(string("escola")) << endl;
    cout << reordenar(string("banana")) << endl;
    cout << reordenar(string("ramide")) << endl;
    cout << reordenar(string("rafael")) << endl;
}
