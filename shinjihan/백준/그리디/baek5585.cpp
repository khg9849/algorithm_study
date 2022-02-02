#include <iostream>

using namespace std;

int main() {

	int money;
	cin >> money;

	money = 1000 - money;

	int count = 0;
	while (money != 0) {
		if (money % 500 == 0) {
			money -= 500;
			count++;
		}
		else if (money % 100 == 0) {
			money -= 100;
			count++;
		}
		else if (money % 50 == 0) {
			money -= 50;
			count++;
		}
		else if (money % 10 == 0) {
			money -= 10;
			count++;
		}
		else if (money % 5 == 0) {
			money -= 5;
			count++;
		}
		else
		{
			money -= 1;
			count++;
		}
	}

	cout << count;

	return 0;
}