#include <iostream>
using namespace std;

int main()
{
    ios :: sync_with_stdio(0);
    cin.tie(0);
    float a, b, c, d, e, f;
    int x , y;
    
    cin >> a >> b >> c >> d >> e >> f;
    // cout << a << b << c << d << e << f;

    y = (c * d - f * a) / (b * d - a * e);
    if (a != 0)
    x = (c - b * y) / a;

    cout << x << ' ' << y << '\n';

    return 0;
}

1 -> 2, 3
2 -> 1, 3

6 -> 5