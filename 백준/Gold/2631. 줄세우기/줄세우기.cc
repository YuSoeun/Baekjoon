#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> A;
vector<int> lis;
int main(int argc, char const *argv[])
{
    cin.tie(); ios::sync_with_stdio(0);
    cin >> N;
    A.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
        int idx = lower_bound(lis.begin(), lis.end(), A[i]) - lis.begin();
        if (idx == lis.size()) {
            lis.push_back(A[i]);
        } else {
            lis[idx] = A[i];
        }
    }

    int result = N - lis.size();
    cout << result << "\n";

    return 0;
}