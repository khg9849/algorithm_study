//Æò±Õ Á¡¼ö
#include <iostream>

using namespace std;

int main() {

	int score = 0;
	int num;

	for (int i = 0; i < 5; i++) {
		cin >> num;
		if (num < 40) {
			score += 40;
		}
		else
		{
			score += num;
		}
	}

	cout << score / 5;

	return 0;
}