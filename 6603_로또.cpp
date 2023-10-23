#include <iostream>
using namespace std;
#include <stack>
#include <queue>

void pick(queue<int> q, vector<int>& v, int pick_size);

int main()
{
    cin.tie(0);
    ios :: sync_with_stdio(0);
    int num, temp;

    while (1) {
        cin >> num;
        if (num == 0) break;
        queue<int> q;
        for (int i = 0; i < num; i++) {
            cin >> temp;
            q.push(temp);
        }
        vector<int> v;
        pick(q, v, 6);
        cout << "\n";
    }

    return 0;
}

void pick(queue<int> q, vector<int>& v, int pick_size)
{
    // 남은 size가 0일 때
    if (pick_size == 0) {
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << "\n";
        return;
    }
    
    if (q.empty()) {
        return;
    }

    int front = q.front();
    q.pop();
    // cout << "front: " << front << endl;
    // cout << q.size() << ", " << pick_size << endl;

    // 1. 첫 숫자 뽑기
    v.push_back(front);
    pick(q, v, pick_size-1);
    v.pop_back();
    
    // 2. 첫 숫자 안 뽑기
    pick(q, v, pick_size);
}