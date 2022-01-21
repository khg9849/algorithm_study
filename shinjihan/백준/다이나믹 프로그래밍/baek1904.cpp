#include <iostream>

using std::cin;
using std::cout;
using std::endl;


int factorial(int num)
{
	int result = 1;
	for (int i = 1; i <= num; ++i)
	{
		result = result * i;
	}
	return result;
}

int main() {

	int n;
	int* arr;

	cin >> n;

	long sum = 0;
   	for (int i = 0; i < n; i++) {
		if (n - 2 * i >= 0) {
			sum += factorial(n - i) / (factorial(n - 2 * i) * factorial(i));
		}
	}

	cout << sum;

	return 0;
}

int main() {

	int n;
	int* arr;

	cin >> n;
	arr = new int[n];

	arr[0] = 1;
	arr[1] = 2;
	for (int i = 2; i < n; i++) {
		arr[i] = (arr[i - 2] + arr[i - 1])%15746;
	}

	cout << arr[n-1];

	return 0;
}