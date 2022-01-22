//다리 놓기
/*
* 강의서쪽 맨밑사이트를 강동쪽 맨밑사이트부터 연결할경우
* 서쪽엔 N-1사이트, 동쪽엔 M-1사이트
* 강의서쪽 맨밑사이트를 강동쪽 맽밑에서 하나위에 사이트에 연결할경우
* 서쪽엔 N-1사이트, 동쪽엔 M-2사이트
* 
* N,M을 행과 열로두고 2차원배열로 표현했을시
* 따라서 dp[i][j] = dp[i][j-1] + dp[i-1][j-1]이란 점화식이 도출된다
*/
/*#include <iostream>

using namespace std;

int main() {

	long long int arr[30][30] = { 0 };

	arr[1][1] = 1;
	for (int i = 1; i < 30; i++) {
		for (int j = i; j < 30; j++) {
			if (i == 1) {
				arr[i][j] = j;
			}
			else if (i == j) {
				arr[i][j] = 1;
			}
			else
			{
				arr[i][j] = arr[i][j - 1] + arr[i - 1][j - 1];
			}
		}
	}

	int n;
	cin >> n;
	
	int row, col;
	for (int i = 0; i < n; i++) {
		cin >> row >> col;
		cout << arr[row][col] << endl;
	}

	return 0;
}*/