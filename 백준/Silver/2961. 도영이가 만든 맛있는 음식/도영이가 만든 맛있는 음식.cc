#include <bits/stdc++.h>
using namespace std;

int N;
long long min_diff = LONG_LONG_MAX;
long long ingredients[11][2];
int visited[11] = {0, };

void cooking(int idx, long long mul, long long tot)
{
    if (idx == N) {
        if (tot > 0) {
            min_diff = min(min_diff, abs(mul - tot));
        }
        return;
    }

    cooking(idx+1, mul, tot);
    cooking(idx+1, mul * ingredients[idx][0], tot + ingredients[idx][1]);

}

int main()
{
    ios::sync_with_stdio(0);    cin.tie(0);
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> ingredients[i][0] >> ingredients[i][1];
    }

    cooking(0, 1, 0);
    cout << min_diff << "\n";

    return 0;
}