#include <bits/stdc++.h>
using namespace std;

// N이 크면 시간초과되는 알고리즘
// 1부터 N까지 돌면서 2와 5로 몇번 나눠지는지

int main()
{
    cin.tie(0); ios::sync_with_stdio(0);
    int N;
    int x = 0, y = 0;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        int num = i;
        cout << "num: " << num << endl;

        while (1) {
            int mod = num % 10;

            if (mod > 0 || num == 0)
                break;
            num /= 10;
            x++;
            y++;
        }

        while (1) {
            int mod = num % 5;

            if (mod > 0 || num == 0)
                break;
            num /= 5;
            y++;
        }

        while (1) {
            int mod = num % 2;

            if (mod > 0 || num == 0)
                break;
            num /= 2;
            x++;
        }
        
        cout << "x: " << x << ", y: " << y << endl;
    }

    if (x < y) {
        cout << x << endl;
    } else {
        cout << y << endl;
    }

    return 0;
}