//퇴사
/*
* 최적의 값을 구하는 문제에선
* 현재의값과 그전값들의 최대값을 비교해보는 기법을
* dp에서 사용해보기
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
		dp[i] = -1; //텅빈값들이 있을수 있으니 -1을 넣어주기
	}

	//그전 dp[i]값중에서 최대로 큰값을 maxValue에 저장해주기
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