#include <bits/stdc++.h>
using namespace std;

int H, W, N, M;

int main() {
    cin.tie(0);  ios::sync_with_stdio(0);

    cin >> H >> W >> N >> M;
    cout << ((H + N) / (N + 1)) * ((W + M) / (M + 1)) << "\n";

    return 0;
}