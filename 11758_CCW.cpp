#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int main()
{
    vector <pair<double, double> > p;
    double x, y;

    for (int i = 0; i < 3; i++) {
        cin >> x >> y;
        p.push_back(make_pair(x, y));
    }

    int result = 0;
    if (p[0].X == p[1].X) {
        if (p[2].X == p[0].X) {
            result = 0;
        } else if (p[2].X > p[0].X) {
            result = 1;
        } else {
            result = -1;
        }
    } else if (p[0].X < p[1].X) {
        y = (p[1].Y - p[0].Y) / (p[1].X - p[0].X) * (p[2].X - p[0].X) + p[0].Y;
        if (y == p[2].Y) {
            result = 0;
        } else if (y < p[2].Y) {
            result = 1;
        } else {
            result = -1;
        }
    } else {
        y = (p[1].Y - p[0].Y) * (p[2].X - p[0].X) / (p[1].X - p[0].X) + p[0].Y;

        if (y == p[2].Y) {
            result = 0;
        } else if (y > p[2].Y) {
            result = 1;
        } else {
            result = -1;
        }
    }
    
    cout << result << "\n";

    return 0;
}