#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, temp, result = 0;
    vector<int> A;
    vector<int> matrix;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> temp;
        A.push_back(temp);
        matrix.push_back(0);
    }

    int count, min = 0;
    for (int i = N-1; i >= 0; i--) {
        int max_cnt = 0;

        for (int j = i; j < N; j++) {
            if (A[j] > A[i]) {
                if (matrix[j] > max_cnt)
                    max_cnt = matrix[j];
            }
        }
        matrix[i] = 1 + max_cnt;
    }

    for (int i : matrix) {
        if (i > result)
            result = i;
    }

    cout << result << "\n";

    return 0;
}