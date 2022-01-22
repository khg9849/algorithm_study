//���
/*
* ������ ���� ���ϴ� ��������
* �����ǰ��� ���������� �ִ밪�� ���غ��� �����
* dp���� ����غ���
*/
#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	int n;
	cin >> n;

	int maxValue;
	int* t = new int[n+1];
	int* p = new int[n+1];
	int* dp = new int[n+1];

	for (int i = 1; i < n+1; i++) {
		cin >> t[i] >> p[i];
		dp[i] = -1; //�ֺ󰪵��� ������ ������ -1�� �־��ֱ�
	}

	//���� dp[i]���߿��� �ִ�� ū���� maxValue�� �������ֱ�
	for (int i = 1; i < n+1 ; i++) {
		maxValue = 0;
		if (i + t[i] <= n + 1) {
			for (int j = 1; j < i; j++) {
				if (j + t[j] <= i && dp[j] > maxValue) {
					maxValue = dp[j];
				}
			}
			dp[i] = p[i] + maxValue;
		}
	}
	
	maxValue = 0;
	for (int i = 1; i < n + 1; i++) {
		if (dp[i] > maxValue) maxValue = dp[i];
	}

	cout << maxValue;

	return 0;
}