#include <bits/stdc++.h>
using namespace std;

#define T first
#define P second

int D[16] = {0, };
vector<pair<int, int> > Day;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n = 0;
    int t, p;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t >> p;
        Day.push_back(make_pair(t, p));
    }

    int delay = 0;
    for (int i = n-1; i >= 0; i--) {
        if (i+Day[i].T <= n) {
            D[i] = max(D[i+Day[i].T] + Day[i].P, D[i+1]);
        } else {
            D[i] = D[i+1];
        }
    }

    cout << D[0] << "\n";

    return 0;
}