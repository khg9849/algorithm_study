#include <iostream>
#include <algorithm>

using namespace std;

int minValue(int** arr, int row, int col) {

	int result;
	int* minArr = new int[2];

	int index = 0;
	for (int i = 0; i < 3; i++) {
		if (i != col) {
			minArr[index] = arr[row - 1][i];
			index++;
		}
	}

	return min(minArr[0], minArr[1]);
}

int main() {

	int n;
	int** arr;

	cin >> n;
	arr = new int* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[3];
	}

	int num = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> num;
			arr[i][j] = num;
		}
	}

	int** newArr;
	newArr = new int* [n];
	for (int i = 0; i < n; i++) {
		newArr[i] = new int[3];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 0) {
				newArr[i][j] = arr[i][j];
			}
			else
			{
				newArr[i][j] = arr[i][j] + minValue(newArr, i, j);
			}
		}
	}
	
	cout << min({ newArr[n - 1][0], newArr[n - 1][1], newArr[n - 1][2] });

	return 0;
}