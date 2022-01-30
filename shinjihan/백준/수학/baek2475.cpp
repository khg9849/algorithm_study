//°ËÁõ¼ö
#include <iostream>
#include <cmath>

using namespace std;

int main() {

	int num;
	int ans = 0;

	for (int i = 0; i < 5; i++) {
		cin >> num;
		ans += pow(num, 2);
	}

	cout << ans % 10;

	return 0;
}