#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int main()
{
    long double x = INT_MAX, y = INT_MAX;
    long long x1, y1, x2, y2;
    long long x3, y3, x4, y4;

    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;
    
    // 두 직선의 방정식이 만나는 점 구하기
    pair <long double, long double> P;

    if (((x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4)) != 0) {
        x = (((x1*y2 - y1*x2) * (x3 - x4))
            - (x1 - x2) * (x3*y4 - y3*x4))
            / ((x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4));
    }
    if ((x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4) != 0) {
        y = ((x1*y2 - y1*x2) * (y3 - y4)
            - (y1 - y2) * (x3*y4 - y3*x4))
            / ((x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4));
    }

    P = make_pair(x, y);

    // L1 두 점의 가운데와 cur간 거리가 반지름보다 작거나 같은 지 구하기;
    int flag = 1;
    long double radius, distance;
    pair <long double, long double> L1_cen, L2_cen;

    // L1과 점 사이 거리
    L1_cen = make_pair((x1 + x2)/(long double)2, (y1 + y2)/(long double)2);

    radius = (x2 - L1_cen.X) * (x2 - L1_cen.X) + (y2 - L1_cen.Y) * (y2 - L1_cen.Y);
    distance = (P.X - L1_cen.X) * (P.X - L1_cen.X) + (P.Y - L1_cen.Y) * (P.Y - L1_cen.Y);

    if (radius < distance)
        flag = 0;

    // L2와 점 사이 거리
    L2_cen = make_pair((x3 + x4)/2.0, (y3 + y4)/2.0);

    radius = (x4 - L2_cen.X) * (x4 - L2_cen.X) + (y4 - L2_cen.Y) * (y4 - L2_cen.Y);
    distance = (P.X - L2_cen.X) * (P.X - L2_cen.X) + (P.Y - L2_cen.Y) * (P.Y - L2_cen.Y);

    if (radius < distance)
        flag = 0;

    if (flag == 1) {
        cout << 1 << "\n";
    } else {
        cout << 0 << "\n";
    }

    return 0;
}