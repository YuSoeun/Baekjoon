#include <bits/stdc++.h>
using namespace std;

int H, W;
int heights[505];
int left_max[505], right_max[505];

// 찾아본 정답 코드

int main() {
    cin.tie(0); ios::sync_with_stdio(0);

    cin >> H >> W;
    for (int i = 0; i < W; i++) {
        cin >> heights[i];
    }

    // 1. 왼쪽 최대값 계산
    left_max[0] = heights[0];
    for (int i = 1; i < W; i++) {
        left_max[i] = max(left_max[i-1], heights[i]);
    }

    // 2. 오른쪽 최대값 계산
    right_max[W-1] = heights[W-1];
    for (int i = W-2; i >= 0; i--) {
        right_max[i] = max(right_max[i+1], heights[i]);
    }

    // 3. 각 칸에 물 계산
    int result = 0;
    for (int i = 0; i < W; i++) {
        result += max(0, min(left_max[i], right_max[i]) - heights[i]);
    }

    cout << result << "\n";
    return 0;
}