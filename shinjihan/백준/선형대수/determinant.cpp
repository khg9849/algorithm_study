#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int **setMat(int** arr, int** newArr,int line, int num) {

	int row = 0, col = 0;
	for (int i = 0; i < num; i++) {
		col = 0;
		if (i != line) {
			for (int j = 1; j < num; j++) {
				newArr[row][col] = arr[i][j];
				col++;
			}
			row++;
		}
	}

	return newArr;
}

int determinant(int **arr, int n) {

	int answer = 0;

	if (n > 2) {
		int** newArr;

		newArr = new int* [n - 1];
		for (int i = 0; i < n - 1; i++) {
			newArr[i] = new int[n - 1];
		}

		for (int i = 0; i < n; i++) {
			if (i % 2 == 1) {
				answer -= arr[i][0] * determinant(setMat(arr, newArr, i, n), n - 1);
			}
			else
			{
				answer += arr[i][0] * determinant(setMat(arr, newArr, i, n), n - 1);
			}
		}
		
		return answer;
	}
	else
	{
		return arr[0][0] * arr[1][1] - arr[0][1] * arr[1][0];
	}
	
}

int main() {

	int **arr = new int*[5];

	for (int i = 0; i < 5; i++) {
		arr[i] = new int[5];
		for (int j = 0; j < 5; j++) {
			cin >> arr[i][j];
		}
	}

	cout << determinant(arr, 5);

	return 0;
}