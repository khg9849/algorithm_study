/*#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    int n;
    int ans = 0;

    cin >> n;
    int* arr = new int[n];
    int* result = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    result[0] = arr[0];
    ans = result[0];

    for (int i = 1; i < n; i++) {
        result[i] = max(result[i - 1] + arr[i], arr[i]);
        ans = max(ans, result[i]);
    }

    printf("%d", ans);

    return 0;
}*/