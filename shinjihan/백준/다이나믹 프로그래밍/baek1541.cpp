#include <iostream>
#include <string>
#define INTMAX 2100000000

using std::cin;
using std::cout;
using std::endl;

void reset(char str[6]) {

	for (int i = 0; i<6; i++) {
		str[i] = '\0';
	}

	return;
}

int main(void) {

	char input[51];
	int int_input[51] = { 0, };
	char number[6];

	cin >> input;

	int count = 0;
	int num_length = 0;
	for (int i = 0; i < strlen(input); i++) {
		if (input[i] == '+') {
			int_input[count] = atoi(number);
			count++;
			int_input[count] = 1;
			count++;
			num_length = 0;
			reset(number);
		}
		else if (input[i] == '-') {
			int_input[count] = atoi(number);
			count++;
			int_input[count] = 0;
			count++;
			num_length = 0;
			reset(number);
		}
		else
		{
			number[num_length] = input[i];
			num_length++;
		}
	}
	int_input[count] = atoi(number);
	count++;

	int answer = INTMAX;
	num_length = 0;
	for (int i = 1; i <= count; i+=2) {
		if (int_input[i] == 1) {
			int_input[i + 1] = int_input[i - 1] + int_input[i + 1];
		}
		if (int_input[i] == 0) {
			if (answer == INTMAX) {
				answer = int_input[i - 1];
				num_length++;
			}
			else
			{
				answer -= int_input[i - 1];
				num_length++;
			}
		}
	}
	num_length++;

	cout << answer;

	
	return 0;
}