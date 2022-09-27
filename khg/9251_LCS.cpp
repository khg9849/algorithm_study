#include<iostream>
#include<algorithm>
#include<vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;


int main() {

	string Array;
	string Brray;
	cin >> Array >> Brray;
	

	int num1 = Array.length();
	int num2 = Brray.length();


	int** dp = new int* [num1];
	for (int i = 0; i < num1; i++) {
		dp[i] = new int[num2+1];
		dp[i][0] = 0;
	}


	for (int i = 0; i < num1; i++) {
		for (int j = 0; j < num2; j++) {
			if (Array_A[i] != Array_B[j]) {

				if (i == 0) {
					dp[i][j + 1] = dp[i][j];
				}
				else {
					if (dp[i][j] < dp[i - 1][j + 1]) {
						dp[i][j + 1] = dp[i - 1][j + 1];
					}
					else
						dp[i][j + 1] = dp[i][j];
				}
			}
			else {
				if (i == 0) {
					dp[i][j + 1] = 1;
				}
				else {
					dp[i][j + 1] = dp[i - 1][j] + 1;
				}
			}
		}
	}



	for (int i = 0; i < num1; i++) {
		for (int j = 0; j < num2; j++) {
			if (Array_A[i] != Array_B[j]) {
				if (i == 0) {
					dp[i][j + 1] = dp[i][j];
				}
				else {
					if (dp[i][j] < dp[i - 1][j + 1]) {
						dp[i][j + 1] = dp[i - 1][j + 1];
					}
					else
						dp[i][j + 1] = dp[i][j];
				}
			}
			else {
				if (i == 0) {
					dp[i][j + 1] = 1;
				}
				else {
					dp[i][j + 1] = dp[i - 1][j] + 1;
				}
			}
		}
	}

	
	cout << dp[num1 - 1][num2];

	return 0;
}