/*
* 2*n타일에서 생각했단
* 한줄을 빼면 n-1의 경우의 수와 같고
* 두줄을 뺄경우 n-2의 경우의 수와 같단 방식에서 변형되어
* 2*2의 타일은 1*2의 타일이 2개있는 경우와 같으니
* n-2의 경우에 곱하기 2를 해주면 된다
*/
/*#include <iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	long long int arr[1001];

	arr[1] = 1;
	arr[2] = 3;
	for (int i = 3; i < 1001; i++) {
		arr[i] = (arr[i - 1] + arr[i - 2] * 2) % 10007;
	}

	cout << arr[n];

	return 0;
}*/