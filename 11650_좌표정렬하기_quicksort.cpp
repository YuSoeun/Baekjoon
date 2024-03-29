/*
    문제
    2차원 평면 위의 점 N개가 주어진다. 좌표를 x좌표가 증가하는 순으로, x좌표가 같으면 y좌표가 증가하는 순서로 정렬한 다음 출력하는 
    프로그램을 작성하시오.

    입력
    첫째 줄에 점의 개수 N (1 ≤ N ≤ 100,000)이 주어진다. 둘째 줄부터 N개의 줄에는 i번점의 위치 xi와 yi가 주어진다. 
    (-100,000 ≤ xi, yi ≤ 100,000) 좌표는 항상 정수이고, 위치가 같은 두 점은 없다.

    출력
    첫째 줄부터 N개의 줄에 점을 정렬한 결과를 출력한다.
*/

#include <iostream>
#include <algorithm>
using namespace std;

typedef struct
{
    int x;      // -100,000 ≤ xi, yi ≤ 100,000
    int y;
} Point;

bool cmp(const Point &p1, const Point &p2)
{
    if (p1.x < p2.x) {
        return true;
    } else if (p1.x == p2.x) {
        return p1.y < p2.y;
    }

    return false;
}

typedef Point DATA;

int main()
{
    Point * p;
    int n;

    cin >> n;

    p = (Point *)malloc(sizeof(Point) * n);

    for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
    }

    sort(p, p + n, cmp);

    for (int i = 0; i < n; i++) {
        cout << p[i].x << " " << p[i].y << "\n";
    }

    return 0;
}

void quick_sort(DATA * a, int pivot, int low, int high)
{
    DATA temp;
    int n = high - pivot + 1;

    while (low <= high) {
        if (cmp(a[low], a[pivot])) {
            if (cmp(a[high], a[pivot])) {
                high--;
            } else {
                temp = a[high];
                a[high] = a[low];
                a[low] = temp;
            }
        } else {
            low++;
        }

        // cout << high << "--\n";

        if (cmp(a[high], a[pivot])) {
            high--;
        }
    }

    temp = a[pivot];
    a[pivot] = a[high];
    a[high] = temp;

#ifdef DEBUG
    for (int i = 0; i < n; i++) {
        cout << a[pivot+i] << ' ';
    }
    cout << '\n';
#endif

    ++pivot;

    if (high > pivot) {
        quick_sort(a, pivot, pivot + 1, high - 1);
    }
    if (high + 1 < n - 1) {
        quick_sort(a, high + 1, high + 2, n - 1);
    }
}