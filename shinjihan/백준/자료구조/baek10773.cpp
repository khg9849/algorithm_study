/*#include <iostream>
#include <stack>

using namespace std;

int main() {

	int n;
	cin >> n;

	stack<int> st;
	int num;
	int result = 0;

	for (int i = 0; i < n; i++) {
		cin >> num;
		if (num != 0) {
			st.push(num);
		}
		else
		{
			st.pop();
		}
	}

	while (!st.empty()) {
		result += st.top();
		st.pop();
	}

	cout << result;

	return 0;
}*/