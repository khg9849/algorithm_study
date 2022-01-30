/*#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main() {

	int n;
	cin >> n;

	queue<int> q;
	string str;

	int input = 0;
	for (int i = 0; i < n; i++) {
		cin >> str;
		if (str.compare("push") == 0) {
			cin >> input;
			q.push(input);
		}
		else if (str.compare("pop") == 0) {
			if (q.empty()) {
				cout << "-1" << endl;
			}
			else
			{
				cout << q.front() << endl;
				q.pop();
			}
		}
		else if (str.compare("size") == 0) {
			cout << q.size() << endl;
		}
		else if (str.compare("empty") == 0) {
			if (q.empty()) {
				cout << "1" << endl;
			}
			else
			{
				cout << "0" << endl;
			}
		}
		else if (str.compare("front") == 0) {
			if (q.empty()) {
				cout << "-1" << endl;
			}
			else
			{
				cout << q.front() << endl;
			}
		}
		else if (str.compare("back") == 0) {
			if (q.empty()) {
				cout << "-1" << endl;
			}
			else
			{
				cout << q.back() << endl;
			}
		}

	}

	return 0;
}*/