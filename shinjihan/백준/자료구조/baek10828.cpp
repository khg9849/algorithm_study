/*#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {

	int n;
	cin >> n;

	stack<int> stack;
	string str;

	int input = 0;
	for (int i = 0; i < n; i++) {
		cin >> str;
		if (str.compare("push") == 0) {
			cin >> input;
			stack.push(input);
		}
		else if (str.compare("pop") == 0) {
			if (stack.empty()) {
				cout << "-1" << endl;
			}
			else
			{
				cout << stack.top() << endl;
				stack.pop();
			}
		}
		else if (str.compare("size") == 0) {
			cout << stack.size() << endl;
		}
		else if (str.compare("empty") == 0) {
			if (stack.empty()) {
				cout << "1" << endl;
			}
			else
			{
				cout << "0" << endl;
			}
		}
		else if (str.compare("top") == 0) {
			if (stack.empty()) {
				cout << "-1" << endl;
			}
			else
			{
				cout << stack.top() << endl;
			}
		}

	}

	return 0;
}*/