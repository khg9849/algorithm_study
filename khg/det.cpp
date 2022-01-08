#include<iostream>

using std::cin;
using std::cout;
using std::endl;

int determinant(int** A, int n);
void set_mat(int **A, int** B, int i, int n);
int main() {
	int** A = new int* [5];
	for (int i = 0; i < 5; i++) {
		A[i] = new int[5];
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> A[i][j];
		}
	}

	cout << determinant(A, 5);
}

int determinant(int** A, int n) {
	int sum = 0;
	if (n > 2) {
		int** B = new int* [n - 1];
		for (int i = 0; i < n - 1; i++) {
			B[i] = new int[n - 1];
		}


		for (int i = 0; i < n; i++) {
			set_mat(A, B, i, n);
			if (i % 2 == 0) {
				sum += A[i][0] * determinant(B, n - 1);
			}
			else
				sum -= A[i][0] * determinant(B, n - 1);
		}
		return sum;
	}
	else if(n == 2) {
		return (A[0][0] * A[1][1]) - (A[1][0] * A[0][1]);
	}
}
void set_mat(int** A, int** B, int i, int n) {
	int m1=0, m2=0;
	for (int j = 0; j < n; j++) {
		m2 = 0;
		if (j != i) {
			for (int k = 1; k < n; k++) {
				
				B[m1][m2] = A[j][k];
				m2++;
				
			}
			m1++;
		}
		if (m1 == n - 1)
			break;
	}
}