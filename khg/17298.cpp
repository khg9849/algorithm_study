#include<iostream>
#include<vector>
#define _CRT_SECURE_NO_WARNINGS
using std::cin;
using std::cout;
using std::vector;


int main() {

	int N;
	int temp;
	vector<int> st1, st2, st3;
	cin >> N;
	int* A = new int[N];
	int* NGE = new int[N];
	int count;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		st1.push_back(temp);
	}
	count = N;
	st2.push_back(st1.back());
	st1.pop_back();
	NGE[--count] = -1;
	while (count) {
		if (st1.back() < st2.back()) {
			NGE[--count] = st2.back();
			st2.push_back(st1.back());
			st1.pop_back();
			
		}
		else {
			st2.pop_back();
			if (st2.empty()) {
				st2.push_back(st1.back());
				st1.pop_back();
				NGE[--count] = -1;
			}
		}

	}

	for (int i = 0; i < N; i++) {
		printf("%d ", NGE[i]);
	}
	return 0;
}