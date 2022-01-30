#include <iostream> 
#define max 2100000000

using namespace std;

void swap(int* arr, int a, int b) {
	
	int temp = 0;

	temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;

	return;
}

void heap_push(int* arr, int num, int i) {

	arr[i] = num;
	

	while (1) {
		if (arr[i] < arr[(i - 1) / 2]) {
			swap(arr, i, (i - 1) / 2);
			i = (i - 1) / 2;
		}
		else
		{
			break;
		}
	}

	return;
}

int* heap_pop(int* arr, int* result, int n, int index) {

	*result = arr[0];
	int temp = 0;

	int* newArr = new int[n];
	newArr[0] = arr[index];
	arr[index] = max;
	for (int i = 1; i < n; i++) {
		newArr[i] = arr[i];
	}

	while (1) {
		if (newArr[temp] > newArr[temp * 2 + 1] && newArr[temp] > newArr[temp * 2 + 2]) {
			if (newArr[temp * 2 + 1] < newArr[temp * 2 + 2]) {
				newArr[temp] = newArr[temp * 2 + 1];
				newArr[temp * 2 + 1] = max;
				temp = temp * 2 + 1;
			}
			else
			{
				newArr[temp] = newArr[temp * 2 + 2];
				newArr[temp * 2 + 2] = max;
				temp = temp * 2 + 2;
			}
		}
		else if (newArr[temp] > newArr[temp * 2 + 1]) {
			newArr[temp] = newArr[temp * 2 + 1];
			newArr[temp * 2 + 1] = max;
			temp = temp * 2 + 1;
		}
		else if (newArr[temp] > newArr[temp * 2 + 2]) {
			newArr[temp] = newArr[temp * 2 + 2];
			newArr[temp * 2 + 2] = max;
			temp = temp * 2 + 2;
		}
		else
		{
			break;
		}
	}

	return newArr;
}

int main() {

	int n;
	cin >> n;

	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		arr[i] = max;
	}
	int num;
	int index = 0;
	int result = 0;
	int count = 0;

	for (int i = 0; i < n; i++) {
		cin >> num;
		if (num == 0) {
			if (count == 0) {
				cout << 0 << endl;
			}
			else
			{
				arr = heap_pop(arr, &result, n, index-1);
				cout << result << endl;
				count--;
			}
		}
		else
		{
			heap_push(arr, num, index);
			index++;
			count++;
		}
	}

	

	return 0;
}