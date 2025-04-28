#include <bits/stdc++.h>
using namespace std;
int N;
vector<int> A;

int doCalculate(int a, int b, int op) {
    if (op == 0) {
        return a + b;
    } else if (op == 1) {
        return a - b;
    } else if (op == 2) {
        return a * b;
    } else if (op == 3) {
        return a / b;
    } else {
        perror("wrong op\n");
        return -1;
    }
} 

int max_sum = -INT_MAX, min_sum = INT_MAX;      // max_sum도 -INT_MAX로 설정해주기!
int calculateSum(vector<int> operat, int sum, int len, int op)
{
    if (op != -1)
        operat[op]--;
    
    if (len >= N) {
        if (sum > max_sum)
            max_sum = sum;
        if (sum < min_sum)
            min_sum = sum;
        return 0;
    }

    int new_sum;
    for (int i = 0; i < 4; i++) {
        if (operat[i] > 0) {
            new_sum = doCalculate(sum, A[len], i);
            calculateSum(operat, new_sum, len+1, i);
        }
    }
    
    return sum;
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(0);
    vector<int> operat(4, 0);
    int temp;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> temp;
        A.push_back(temp);
    }

    for (int i = 0 ; i < 4; i++) {
        cin >> temp;
        operat[i] = temp;
    }

    calculateSum(operat, A[0], 1, -1);
    cout << max_sum << "\n";
    cout << min_sum << "\n";

    return 0;
}