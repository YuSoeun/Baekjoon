#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    string temp;
    vector<string> a, b, result;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        a.push_back(temp);
    }
    for (int i = 0; i < m; i++) {
        cin >> temp;
        b.push_back(temp);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int i = 0, j = 0;
    while (1) {
        if (i >= n || j >= m)
            break;
        if (a[i] == b[j]) {
            result.push_back(a[i]);
            i++;  j++;
        } else if (a[i] > b[j]) {
            j++;
        } else {
            i++;
        }
    }

    int size = result.size();
    cout << size << "\n";
    for (int i = 0; i < size; i++) {
        cout << result[i] << "\n";
    }

    return 0;
}