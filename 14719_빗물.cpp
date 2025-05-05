#include <bits/stdc++.h>
using namespace std;

int H, W;

// 30분, 풀고 정석 풀이 찾아봄

int main() {
    cin.tie(0);  ios::sync_with_stdio(0);

    cin >> H >> W;
    vector<int> visited(W, 0);
    vector<int> heights(W, 0);
    for (int w = 0; w < W; w++) {
        cin >> heights[w];
    }

    int result = 0;
    for (int h = H; h >= 1; h--) {
        vector<int> higher;
        for (int w = 0; w < W; w++) {
            if (!visited[w] && heights[w] >= h) {
                higher.push_back(w);
            }
        }
        if (higher.size() < 2) continue;

        for (int i = 0; i < higher.size() - 1; i++) {
            int start = higher[i];
            int end = higher[i + 1];
            for (int j = start + 1; j < end; j++) {
                if (!visited[j]) {
                    result += (h - heights[j]);
                    visited[j] = 1;
                }
            }
        }
    }

    cout << result << "\n";
    return 0;
}