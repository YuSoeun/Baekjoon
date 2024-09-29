#include <bits/stdc++.h>
using namespace std;
// pq 코드

int main()
{
    cin.tie(0);  ios::sync_with_stdio(0);
    int N, temp;

    cin >> N;
    priority_queue<int> pq;

    for (int i = 0; i < N*N; i++) {
        cin >> temp;
        if (pq.size() >= N) {
            pq.pop();
        }
        pq.push(temp);
    }

    cout << pq.top() << endl;

    return 0;
}