#include <bits/stdc++.h>

int main()
{
    int n, max_index;
    vector <int> a;         // index까지의 숫자 합

    cin >> n;
    a.push_back(0);
    max_index = n / 2 + n % 2;

    for (int i = 1; i <= max_index; i++) {
        a.push_back(i + a[i-1]);
        cout << a[i] << "\n";
    }

    int i = 0, j = max_index;
    int count = 0;
    while (j > i) {
        // TODO: 알고리즘 다시 생각
        int temp = a[j] - a[i];
        // if (temp > n) {
        //     i++;
        // } else if (temp == n) {
        //     count++;
        //     j++;
        // } else {
        //     j--;
        // }
    }

    return 0;
}