//상근날드
#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	int buger1, buger2, buger3;
	int coke1, coke2;

	cin >> buger1 >> buger2 >> buger3 >> coke1 >> coke2;

	cout << min({ buger1, buger2, buger3 }) + min(coke1, coke2) - 50;

	return 0;
}