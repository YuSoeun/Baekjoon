#include <bits/stdc++.h>
using namespace std;

int main()
{
    int X, bitCount = 0;
    cin >> X;

    for (int i = 0; i <= 6; i++) {
        if ((X & (1 << i)) != 0)
            bitCount++;
    }
    cout << bitCount << endl;

    return 0;
}