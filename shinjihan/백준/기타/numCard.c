#include <stdio.h>
#include <stdlib.h>

int upperBound(int*, int, int);
int lowerBound(int*, int, int);
int compare(const void*, const void*);

int main(void) {

	int N;
	scanf(" %d", &N);

	int* arr;
	arr = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++) {
		scanf(" %d", &arr[i]);
	}

	qsort(arr, N, sizeof(arr[0]), compare);

	int M, num;
	scanf(" %d", &M);

	for (int i = 0; i < M; i++) {
		scanf(" %d", &num);
		//printf("%d %d = %d\n", upperBound(arr, N, num), lowerBound(arr, N, num), upperBound(arr, N, num) - lowerBound(arr, N, num));
		printf("%d ", upperBound(arr, N, num) - lowerBound(arr, N, num));
	}

	return 0;
}

int upperBound(int* arr, int size, int num) {
	
	int top, bottom, mid;
	top = size - 1;
	bottom = 0;
	mid = (top + bottom) / 2;
	num++;

	while (top >= bottom) {
		switch (compare(&arr[mid], &num)) {
		case 0:
			while (1) {
				if (arr[mid - 1] == arr[mid]) {
					mid--;
				}
				else
				{
					break;
				}
			}
			return mid;
		case 1:
			top = mid - 1;
			mid = (top + bottom) / 2;
			break;
		case -1:
			bottom = mid + 1;
			mid = (top + bottom) / 2;
		}
	}

	return bottom;
}

int lowerBound(int* arr, int size, int num) {
	
	int top, bottom, mid;
	top = size - 1;
	bottom = 0;
	mid = (top + bottom) / 2;
	num--;

	while (top >= bottom) {
		switch (compare(&arr[mid], &num)) {
		case 0:
			while (1) {
				if (arr[mid + 1] == arr[mid]) {
					mid++;
				}
				else
				{
					break;
				}
			}
			return mid+1;
		case 1:
			top = mid - 1;
			mid = (top + bottom) / 2;
			break;
		case -1:
			bottom = mid + 1;
			mid = (top + bottom) / 2;
		}
	}

	return bottom;
}

int compare(const void* a, const void* b) {
	int num1 = *(int*)a;
	int num2 = *(int*)b;

	if (num1 < num2)
		return -1;

	if (num1 > num2)
		return 1;

	return 0;
}