//�ִ����� �ּҰ����
//��Ŭ����ȣ����
#include <iostream>

using namespace std;

int uclid(int n, int m) {

	if (n % m == 0) {
		return m;
	}
	else
	{
		return uclid(m, n % m);
	}

	return 0;
}

int main() {

	int n, m;
	cin >> n >> m;

	cout << uclid(n, m) << endl << n * m / uclid(n, m);
	
	return 0;
}