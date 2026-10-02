#include <iostream>
#include <vector>

using namespace std;

class MinStack {
	vector<int> valores;
	vector<int> minimos;
	int n;

public:
	explicit MinStack(int cap) : valores(cap), minimos(cap), n(0) {
	}

	void push(int val) {
		valores[n] = val;

		if (n == 0) {
			minimos[n] = val;
		}
		else if (val < minimos[n-1]) {
			minimos[n] = val;
		}
		else {
			minimos[n] = minimos[n-1];
		}

		n++;
	}

	void pop() {
		n--;
	}

	int top() const {
		return valores[n-1];
	}

	int getMin() const {
		return minimos[n-1];
	}
};

int main() {

    MinStack minStack(10);
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << minStack.getMin() << endl; // -3
    minStack.pop();
    cout << minStack.getMin() << endl; // -2
    minStack.push(-10);
    minStack.push(-10);
    cout << minStack.getMin() << endl; // -10
    minStack.pop();
    cout << minStack.getMin() << endl; // -10
    minStack.pop();
    cout << minStack.getMin() << endl; // -2

    return 0;
}