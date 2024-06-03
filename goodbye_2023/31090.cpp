#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, temp, mod;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> temp;
        mod = temp % 100;

        if ((temp+1) % mod == 0) {
            cout << "Good\n";
        } else {
            cout << "Bye\n";
        }
    }

    return 0;
}