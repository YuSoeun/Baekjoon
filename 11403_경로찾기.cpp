#include <bits/stdc++.h>
using namespace std;

int matrix[101][101] = {0, };

int main()
{
    int n;
    bool exist;
    
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> exist;
            matrix[i][j] = exist;
        }
    }

    for (int num = 0; num < n; num++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][num] && num != i) {
                    if (matrix[num][j] && num != j) {
                        matrix[i][j] = 1;
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}