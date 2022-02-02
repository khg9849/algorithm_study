#include <iostream>

using namespace std;

int main() {

	int time;
	cin >> time;

	int a_count = 0;
	int b_count = 0;
	int c_count = 0;

	int check = 0;
	while (time != 0) {
		if (time % 300 == 0) {
			time -= 300;
			a_count++;
		}
		else if (time % 60 == 0) {
			time -= 60;
			b_count++;
		}
		else if (time % 10 == 0) {
			time -= 10;
			c_count++;
		}
		else {
			check = 1;
			break;
		}
	}

	if (check == 0) {
		cout << a_count << " " << b_count << " " << c_count;
	}
	else
	{
		cout << -1;
	}

	return 0;
}