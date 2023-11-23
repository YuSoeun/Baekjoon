#include <bits/stdc++.h>
using namespace std;
string a, b;
int c1, c2;
int matrix[1001][1001];

// int getLCS(int count, int left, int right) {
//     // 재귀 ?
//     if (left >= a1.length() || right >= a2.length()) {
//         return 0;
//     }

//     // cout << "a1[left]: " << a1[left] << "\n";
//     // cout << "a2[right]: " << a2[right] << "\n";
//     if (a1[left] == a2[right]) {
//         count = 1 + getLCS(count, left+1, right+1);
//     } else {
//         c1 = getLCS(count, left+1, right);
//         c2 = getLCS(count, left, right+1);

//         if (c1 > c2)    count = c1;
//         else            count = c2;
//     }
//     return count;
// }

int main()
{
    int count, max = 0;
    int c1 = 0, c2 = 0;
    int cur = 0;
    int x = 0, y = 0;

    cin >> a >> b;
    int a_len = a.length();
    int b_len = b.length();

    // 0번째 index setting
    for (int i = 0; i < a_len; i++) {
        matrix[i][0] = 0;
    }
    for (int j = 0; j < b_len; j++) {
        matrix[0][j] = 0;
    }

    for (int x = 1; x <= a_len; x++) {
        for (int y = 1; y <= b_len; y++) {
            if (a[x-1] == b[y-1]) {
                matrix[x][y] = 1 + matrix[x-1][y-1];
            } else {
                matrix[x][y] = std::max(matrix[x-1][y], matrix[x][y-1]);
            }
        }
    }

    // for (int x = 0; x <= a_len; x++) {
    //     for (int y = 0; y <= b_len; y++) {
    //         cout << matrix[x][y] << " ";
    //     }
    //     cout << "\n";
    // }

    cout << matrix[a_len][b_len] << "\n";

    return 0;
}