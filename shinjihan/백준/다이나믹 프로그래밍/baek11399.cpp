/*
#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

int compare(const void* a, const void* b) {

	const int* x = (int*)a;
	const int* y = (int*)b;

	if (*x > *y) return 1;
	else if (*x < *y) return -1;
	return 0;
}

int main(void) {

	int n;
	int* people;

	cin >> n;
	people = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> people[i];
	}
	
	qsort(people, n, sizeof(int), compare);
	
	int total = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			total += people[j];
		}
	}

	cout << total;
	
	return 0;
}*/