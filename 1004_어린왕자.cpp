#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, x, y, r;
    pair<int, int> s, d;
    int count = 0;

    cin >> n;

    for (int i = 0; i < n; i++) {
        count = 0;
        cin >> x >> y; s = make_pair(x, y);
        cin >> x >> y; d = make_pair(x, y);

        cin >> m;
        for (int j = 0; j < m; j++) {
            cin >> x >> y;
            cin >> r;

            // s, d 점들과 비교한 distnace
            int distance_s = sqrt(pow(x - s.first, 2) + pow(y - s.second, 2));
            int distance_d = sqrt(pow(x - d.first, 2) + pow(y - d.second, 2));
            
            if (distance_s < r && distance_d < r) {
                ;
            } else if (distance_s < r) {
                count++;
            } else if (distance_d < r) {
                count++;
            }
        }
        cout << count << "\n";
    }

    return 0;
}