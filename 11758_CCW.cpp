#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int main()
{
    vector <pair<int, int> > p;
    int x, y;
    double comp;

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
        comp = (p[1].Y - p[0].Y) * (p[2].X - p[0].X) / (double)(p[1].X - p[0].X) + p[0].Y;
        if (comp == p[2].Y) {
            result = 0;
        } else if (comp < p[2].Y) {
            result = 1;
        } else {
            result = -1;
        }
    } else {
        comp = (p[1].Y - p[0].Y) * (p[2].X - p[0].X) / (double)(p[1].X - p[0].X) + p[0].Y;
        if (comp == p[2].Y) {
            result = 0;
        } else if (comp > p[2].Y) {
            result = 1;
        } else {
            result = -1;
        }
    }
    
    cout << result << "\n";

    return 0;
}