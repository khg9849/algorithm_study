/*#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {

    int arr[21][21][21];
    
    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 21; j++) {
            for (int k = 0; k < 21; k++) {
                if (i <= 0 || j <= 0 || k <= 0) {
                    arr[i][j][k] = 1;
                }
                else if (i < j && j < k) {
                    arr[i][j][k] = arr[i][j][k - 1] + arr[i][j - 1][k - 1] - arr[i][j - 1][k];
                }
                else
                {
                    arr[i][j][k] = arr[i - 1][j][k] + arr[i - 1][j - 1][k] + arr[i - 1][j][k - 1] - arr[i - 1][j - 1][k - 1];
                }
            }
        }
    }

    int a, b, c;
    
    cin >> a >> b >> c;
    while (a != -1 || b != -1 || c != -1) {

        if (a > 20 || b > 20 || c > 20) {
            printf("w(%d, %d, %d) = %d\n", a, b, c, arr[20][20][20]);
        }
        else if (a <= 0 || b <= 0 || c <= 0)
        {
            printf("w(%d, %d, %d) = 1", a, b, c);
        }
        else
        {
            printf("w(%d, %d, %d) = %d\n", a, b, c, arr[a][b][c]);
        }
        
        cin >> a >> b >> c;
    }

	return 0;
}*/