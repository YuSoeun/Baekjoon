#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    long long x, y, x2, y2;
    long long tempx, tempy;
    long long result = 0LL;
    vector <pair <long long, long long> > points;

    cin >> n >> x >> y;
    cin >> x2 >> y2;

    for (int i = 0; i < n-2; i++) {
        cin >> tempx >> tempy;
        // points.push_back(make_pair(tempx, tempy));
        result += (tempx-x)*(y2-y) - (x2-x)*(tempy-y);
        x2 = tempx;  y2 = tempy;
    }
                        //   bx  * ay     -  ax   *   by

    printf("%lld.%lld\n", abs(result/2), abs((result%2)*5));
    // printf("%.1f\n", result/2.0);

    return 0;
}