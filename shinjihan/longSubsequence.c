#include <stdio.h>

int num[1000];
int check[1000];

int main(void) {

	int count;
	
	scanf(" %d", &count);

	for (int i = 0; i < count; i++) {
		scanf(" %d", &num[i]);
	}

	int min;
	for (int i = 0; i < count; i++) {
		min = 0;
		for (int j = 0; j < i; j++) {
			if (num[j] < num[i]) {
				if (min < check[j]) {
					min = check[j];
				}
			}
		}
		check[i] = min + 1;
	}

	int temp = 0;
	for (int i = 0; i < count; i++) {
		if (check[i] > temp) {
			temp = check[i];
		}
	}
	printf("%d", temp);

	return 0;
}