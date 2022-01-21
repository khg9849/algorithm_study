/*#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {

	int count;
	long long int arr[100];

	cin >> count;

	arr[0] = 1;
	arr[1] = 1;
	arr[2] = 1;
	arr[3] = 2;
	arr[4] = 2;
	for (int i = 5; i < 100; i++) {
		arr[i] = arr[i - 1] + arr[i - 5];
	}

	int num = 0;
	for (int i = 0; i < count; i++) {
		cin >> num;
		cout << arr[num-1] << endl;
	}

	return 0;
}*/