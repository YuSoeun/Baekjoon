#include <bits/stdc++.h>
using namespace std;

int main()
{
    int result = 0;
    int N;
    cin >> N;

    vector<pair<int, int> > col(N); // 위치, 기둥
    pair<int, int> max;
    for (int i = 0; i < N; i++) {
        cin >> col[i].first >> col[i].second;
        // 처음 나온 가장 큰 기둥 저장
        if (col[i].second > max.second)
            max = col[i];
    }

    sort(col.begin(), col.end());
    const auto it = std::find(col.begin(), col.end(), max);
    auto mid_index = distance(col.begin(), it);

    int l_height = col[0].second, r_height = col[N-1].second;
    int l_width = 0, r_width = 0;
    int x_ago = col[0].first;

    // mid 전 왼쪽 부분 계산
    for (int i = 1; i <= mid_index; i++) {
        // 더 큰 기둥 만나면
        int w = col[i].first - x_ago;
        int h = col[i].second;
        
        l_width += w;
        if (h > l_height) {
            result += l_height * w;
            l_height = h;
            x_ago = col[i].first;
        }
    }
    result += l_height * (col[mid_index].first - x_ago);

    x_ago = col[N-1].first;
    // mid 오른쪽 부분 계산
    for (int i = N - 2; i >= mid_index; i--) {
        int w = x_ago - col[i].first;
        int h = col[i].second;

        if (h >= r_height) {
            result += r_height * w;
            r_height = h;
            x_ago = col[i].first;
        }
    }
    result += l_height * (col[mid_index].first - x_ago);

    // 가운데꺼 더해주기
    result += max.second * 1;
    cout << result << "\n";

    return 0;
}