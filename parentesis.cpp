#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(const string &s) {
        stack<char> pilha;

        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                pilha.push(c);
            }
            else {
                if (pilha.empty()) {
                    return false;
                }
                char top = pilha.top();
                pilha.pop();

                if (top == ')') {
                    return false;
                }

                if (top == '}') {
                    return false;
                }

                if (top == ']') {
                    return false;
                }
            }
        }

        return pilha.empty();
    }
};

int main() {
    string testes[] = {
        "(", // I
        ")", // I
        "()", // V
        "[{()}]", // V
        "()[]{}", // V
        "{[(}])", // I
        "(][){}", // I
        "}{)(][" // I
    };

    for (auto &s : testes) {
        cout << s << ": ";
        cout << (Solution().isValid(s)?"Valida":"Invalida") << endl;
    }
}
