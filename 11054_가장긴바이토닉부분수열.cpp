#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 0, temp, max;
    vector<int> M;  // matrix
    vector<int> U;  // 증가하는 부분 수열
    vector<int> D;  // 감소하는 부분 수열

    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        M.push_back(temp);
        

        // 증가하는 부분 수열
        max = 0;
        for (int j = 0; j < i; j++) {
            if (M[j] < M[i]) {
                if (max < U[j]) {
                    max = U[j];
                }
            }
        }

        U.push_back(1 + max);
        D.push_back(0);
    }

    for (int item : U) {
        // cout << item << " ";
    }
    // cout << endl;

    // 감소하는 부분 수열
    for (int i = n-1; i >= 0; i--) {
        max = 0;
        for (int j = n-1; j > i; j--) {
            if (M[j] < M[i]) {
                if (max < D[j]) {
                    max = D[j];
                }
            }
        }

        D[i] = max + 1;
    }

    for (int item : D) {
        // cout << item << " ";
    }
    // cout << endl;

    int max_u, max_d;
    max = 0;
    for (int i = 0; i < n; i++) {
        max_u = 0;  max_d = D[i];
        for (int j = 0; j < i; j++) {
            if (U[j] < U[i])
                if (max_u < U[j])
                    max_u = U[j];
        }
        for (int j = i; j < n; j++) {
            if (D[j] > D[i])
                if (max_d < D[j])
                    max_d = D[j];
        }

        if (max_u + max_d > max)
            max = max_u + max_d;

        // cout << max << " ";
    }
    // cout << endl;

    cout << max << "\n";

    return 0;
}