//최소공배수
#include <iostream>

using namespace std;

int uclid(int n, int m) {

	if (n % m == 0) {
		return m;
	}
	else
	{
		return uclid(m, n % m);
	}

	return 0;
}

int main() {

	int n;
	int num1, num2;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num1 >> num2;
		cout << num1 * num2 / uclid(num1, num2) << endl;
	}
	return 0;
}