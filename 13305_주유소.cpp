#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, prev, cur;

    cin >> N;
    vector<int> doro_len(N-1);

    for (int i = 0; i < N-1; i++) {
        cin >> doro_len[i];
    }

    long result = 0;
    long length = 0;
    cin >> prev;
    for (int i = 0; i < N-1; i++) {
        length += doro_len[i];
        cin >> cur;

        if (cur < prev) {
            result += length * prev;

            prev = cur;
            length = 0;
        }
    }

    if (length > 0) {
        result += length * prev;
    }

    cout << result << "\n";

    return 0;
}