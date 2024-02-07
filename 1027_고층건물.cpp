#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int main()
{
    int n, temp;
    vector <int> h;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> temp;
        h.push_back(temp);
    }

    float gradient;
    int max_count = 0;
    pair<int, int> cur_dot;

    // 첫번째 점부터 기준점
    for (int i = 0; i < n; i++) {
        int count = 0;
        float max_gradient = -FLT_MAX, l_max_gradient = FLT_MAX;

        cur_dot = make_pair(i, h[i]);

        // 다른 점들과의 기울기 보기
        // right
        for (int j = i+1; j < n; j++) {
            if (j > i) {
                gradient = 1.0 * (cur_dot.Y - h[j]) / (cur_dot.X - j);

                if (gradient > max_gradient) {
                    max_gradient = gradient;
                    count++;
                }
            }
            // cout << "gradient[" << i << ", " << j << "]: " << gradient << " (" << count << ")" << endl;
        }

        // left
        if (i-1 > -1) {
            for (int j = i-1; j >= 0; j--) {
                gradient = 1.0 * (h[j] - cur_dot.Y) / (j - cur_dot.X);
                if (gradient < l_max_gradient) {
                    l_max_gradient = gradient;
                    count++;
                }
                // cout << "gradient[" << i << ", " << j << "]: " << gradient << " (" << count << ")" << endl;
            }
        }
        // cout << "i: " << i << ", count: " << count << endl;

        if (count > max_count)
            max_count = count;
    }

    cout << max_count << "\n";

    return 0;
}