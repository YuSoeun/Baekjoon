#include <bits/stdc++.h>
using namespace std;
// 그냥 list에 때려넣고 sort함수 씀

int main()
{
    cin.tie(0);  ios::sync_with_stdio(0);
    int N;

    cin >> N;
    vector<int> v(N*N);
    for (int i = 0; i < N*N; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end(), greater<int>());

    cout << v[N-1] << endl;

    return 0;
}