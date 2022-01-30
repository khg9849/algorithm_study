/*#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {

	int n;
	cin >> n;

	stack<char> st;
	string str;
	char c;
	int check;

	while (n--) {
		cin >> str;
		check = 0;

		while (!st.empty()) st.pop();

		for (int i = 0; i < str.length(); i++) {
			c = str[i];

			if (c == '(') {
				st.push(str[i]);
			}
			else if (c == ')') {
				if (!st.empty()) {
					st.pop();
				}
				else
				{
					check = 1;
					break;
				}
			}
		}
		
		if (st.empty() && check == 0) {
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}


	return 0;
}*/