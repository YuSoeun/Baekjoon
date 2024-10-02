#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0), ios::sync_with_stdio(0);
    int N, L;
    int temp, index = 0;
    vector<int> input;
    priority_queue<int, vector<int>, greater<int> > pq;
    priority_queue<int, vector<int>, greater<int> > extract_waiting_list;
    // pq에서 빼야할 것 대기줄

    cin >> N >> L;

    for (int i = 0 ; i < N; i++) {
        cin >> temp;
        input.push_back(temp);

        if (pq.size() >= L) {
            extract_waiting_list.push(input[index]);
            index++;
            
            // 대기줄 첫 번째 요소가 일치할 동안 계속 pop
            while (extract_waiting_list.size() > 0 &&
                    extract_waiting_list.top() == pq.top()) {
                pq.pop(); extract_waiting_list.pop();
            }
        }

        pq.push(temp);
        cout << pq.top() << " ";
    }
    cout << "\n";

    return 0;
}