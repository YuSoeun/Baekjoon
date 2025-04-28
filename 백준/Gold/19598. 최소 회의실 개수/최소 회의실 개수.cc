#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;
#define DATA long long

int N;

priority_queue <pair <DATA, char>, vector< pair <DATA, char> >
    , greater< pair <DATA, char> > > pq;    // 인덱스와 1이면 '(', 0이면 ')'

int main() {
    cin.tie(0); ios::sync_with_stdio(0);

    cin >> N;
    DATA start, end;
    for (int i = 0; i < N; i++) {
        cin >> start >> end;
        pq.push({start, 1});
        pq.push({end, 0});
    }

    int prev = -1;
    
    DATA result = 0;
    stack <DATA> s;
    while (!pq.empty()) {
        auto cur = pq.top();  pq.pop();
        if (cur.second == 1) {
            s.push(1);
        } else if (cur.second == 0) {
            result = max(result, (DATA)s.size());
            s.pop();
        }
    }

    cout << result << "\n";

    return 0;
}