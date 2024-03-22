#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x1, x2, y1, y2, r1, r2;
    int result, distance, r;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x1 >> y1 >> r1;
        cin >> x2 >> y2 >> r2;

        distance = (x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1);
        r = (r1 + r2) * (r1 + r2);

        if (x1 == x2 && y1 == y2) {
            result = -1;
            if (r1 != r2)
                result = 0;
        } else if (r > distance) {
            result = 2;
            int temp = (r2 - r1) * (r2 - r1);
            if (temp == distance) {
                result = 1;
            } else if  (temp > distance) {
                result = 0;
            }
        } else if (r == distance) {
            result = 1;
        } else if (r < distance) {
            result = 0;
        }

        cout << result << '\n';
    }

    return 0;
}