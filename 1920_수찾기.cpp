#include <bits/stdc++.h>
using namespace std;

// nlog(n) 까지만
int main()
{
    // 이거 문제였다!!
    cin.tie(0);
    ios::sync_with_stdio(0);

    // 1번
    // set<int> A;
    // int n, m, temp;
    // cin >> n;
    // for (int i = 0; i < n; i++) {
    //     cin >> temp;
    //     A.insert(temp);
    // }

    // cin >> m;
    // for (int i = 0; i < m; i++) {
    //     cin >> temp;
    //     cout << (A.find(temp) != A.end()) << "\n";
    // }

    // 2번
    vector<int> A;
    int n, m, temp;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        A.push_back(temp);
    }
    sort(A.begin(), A.end());

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> temp;
        cout << binary_search(A.begin(), A.end(), temp) << "\n";
    }

    return 0;
}