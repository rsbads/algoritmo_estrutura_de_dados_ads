#include <iostream>
#include <vector>
#include <string>

using namespace std;

string cifrar(const string &str, int k) {
    if (str.length()<= 1) {
        return str;
    }

    int posicao = k % str.length();

    char caracter = str[posicao];

    vector<char> vetor(str.begin(), str.end());

    vetor.erase(vetor.begin() + posicao);

    string resto (vetor.begin(), vetor.end() );

    return caracter + cifrar(resto, k);


    
}

int main() {
    int k = 6;
    cout << cifrar("casa", k) << endl;
    cout << cifrar("escola", k) << endl;
    cout << cifrar("banana", k) << endl;
    cout << cifrar("ifpe", k) << endl;
    cout << cifrar("a", k) << endl;
    cout << cifrar("rafael", k) << endl;
}