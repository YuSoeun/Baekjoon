#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, l, temp;
    struct
    {
        bool operator()(const pair<int, int> l, const pair<int, int> r) const { return l.second > r.second; }
    } customLess;
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(customLess)> pq(customLess);  // 얘의 priority를 second로 정렬
    queue<int> q;

    cin >> n >> l;

    int min = INT_MAX;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        
        q.push(temp);
        pq.push(make_pair(i, temp));
        if (temp < min)
            min = temp;

        if (i > l) {
            // 제일 앞에 queue 빼고 최솟값 재확인
            if (min == q.front()) {
                
            }
            q.pop();
        }
    }

    return 0;
}