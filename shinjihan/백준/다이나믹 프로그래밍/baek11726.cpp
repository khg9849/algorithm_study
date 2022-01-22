/*#include <iostream>

using namespace std;

int main() {

	int n;
	cin >> n;
	
	long long int arr[1001];

	arr[1] = 1;
	arr[2] = 2;
	for (int i = 3; i < 1001; i++) {
		arr[i] = (arr[i - 1] + arr[i - 2])%10007;
	}

	cout << arr[n];

	return 0;
}*/