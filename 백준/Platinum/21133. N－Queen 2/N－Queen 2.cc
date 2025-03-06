#include <bits/stdc++.h>
using namespace std;

int N;

int main(int argc, char const *argv[]) {
    cin.tie(0);  ios::sync_with_stdio(0);
    cin >> N;

    int t = N / 2;
    vector<int> ans;

    if (N % 6 == 2) {
        for (int i = 1; i <= t; i++) ans.push_back(i * 2);
        ans.push_back(3);
        ans.push_back(1);
        for (int i = 3; i < t; i++)  ans.push_back(i * 2 + 1);
        ans.push_back(5);
    } else if (N % 6 == 3) {
        for (int i = 2; i <= t; i++) ans.push_back(i * 2);
        ans.push_back(2);
        for (int i = 2; i <= t; i++) ans.push_back(i * 2 + 1);
        ans.push_back(1);
        ans.push_back(3);
    } else {
        for (int i = 1; i <= t; i++) {
            ans.push_back(i + t);
            ans.push_back(i);
        }
        if (N % 2 == 1) ans.push_back(N);
    }

    for (int x : ans) cout << x << '\n';

    return 0;
}