/*#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	int n;
	
	cin >> n;
	int* arr = new int[n];
	int* result = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	result[0] = arr[0];
	result[1] = max(arr[0]+arr[1], arr[1]);
	result[2] = max(arr[0] + arr[2], arr[1] + arr[2]);
	for (int i = 3; i < n; i++) {
		result[i] = max(arr[i] + result[i - 2], arr[i] + arr[i - 1] + result[i - 3]);
	}
	
	cout << result[n - 1];

	return 0;
}*/