//�ٸ� ����
/*
* ���Ǽ��� �ǹػ���Ʈ�� ������ �ǹػ���Ʈ���� �����Ұ��
* ���ʿ� N-1����Ʈ, ���ʿ� M-1����Ʈ
* ���Ǽ��� �ǹػ���Ʈ�� ������ ���ؿ��� �ϳ����� ����Ʈ�� �����Ұ��
* ���ʿ� N-1����Ʈ, ���ʿ� M-2����Ʈ
* 
* N,M�� ��� ���εΰ� 2�����迭�� ǥ��������
* ���� dp[i][j] = dp[i][j-1] + dp[i-1][j-1]�̶� ��ȭ���� ����ȴ�
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