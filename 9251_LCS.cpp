#include <bits/stdc++.h>
using namespace std;
string a1, a2;
int c1, c2;

int getLCS(int count, int left, int right) {
    // 재귀 ?
    if (left >= a1.length() || right >= a2.length()) {
        return 0;
    }

    // cout << "a1[left]: " << a1[left] << "\n";
    // cout << "a2[right]: " << a2[right] << "\n";
    if (a1[left] == a2[right]) {
        count = 1 + getLCS(count, left+1, right+1);
    } else {
        c1 = getLCS(count, left+1, right);
        c2 = getLCS(count, left, right+1);

        if (c1 > c2)    count = c1;
        else            count = c2;
    }
    return count;
}

int main()
{
    int i_a1, i_a2;
    int count, max = 0;

    cin >> a1 >> a2;

    count = getLCS(0, 0, 0);

    cout << count << "\n";

    return 0;
}