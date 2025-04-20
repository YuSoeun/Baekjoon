#include <bits/stdc++.h>
using namespace std;

int N, M;
vector <int> lesson;
int maxValue = 0;

int isValid(int target, int size) {
    int total = 0;

    for (int i = 0; i < N; i++) {
        if (lesson[i] > target) return 0;

        total += lesson[i];
        if (total > target) {
            total = lesson[i];
            size--;
        }
        if (size <= 0) {
            return 0;
        }
    }

    return 1;
}

int main(int argc, char const *argv[]) {
    cin.tie(0);  ios::sync_with_stdio(0);
    cin >> N >> M;

    lesson.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> lesson[i];
        maxValue += lesson[i];
    }

    int start = 0;
    int end = maxValue;
    int result = maxValue;
    while (start < end) {
        int mid = (start + end) / 2;
        if (isValid(mid, M)) {
            result = min(result, mid);
            end = mid;
        } else {
            start = mid + 1;
        }
    }

    cout << result << "\n";

    return 0;
}