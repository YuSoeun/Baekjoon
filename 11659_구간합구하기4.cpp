#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    vector <int> sum;   // 0부터 index까지의 합
    cin >> n >> m;

    sum.push_back(0);
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        sum.push_back(temp + sum[i]);
    }

    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        cout << sum[y] - sum[x-1] << "\n";
    }

    return 0;
}