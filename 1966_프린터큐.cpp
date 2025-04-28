#include <bits/stdc++.h>
using namespace std;

#define INDEX first
#define PRIORITY second

int main()
{
    int t, n, dest, priority;
    pair <int, int> temp;

    cin >> t;

    // 여러 테스트 케이스
    for (int i = 0; i < t; i++) {
        vector <int> v;
        vector <pair <int, int> > v_q;

        cin >> n >> dest;

        for (int j = 0; j < n; j++) {
            cin >> priority;

            v.push_back(priority);
            v_q.push_back(make_pair(j, priority));
        }

        sort(v.begin(), v.end(), greater());

        int j = 0, k = 0;
        while (j < n) {
            if (v_q[j].PRIORITY < v[k]) {
                temp = v_q[j];  v_q.erase(v_q.begin() + j);
                v_q.push_back(temp);
            } else if (v_q[j].PRIORITY >= v[k]) {
                j++;  k++;
            }
        }

        for (int j = 0; j < n; j++) {
            if (v_q[j].INDEX == dest) {
                cout << j + 1 << "\n";
                break;
            }
        }
    }

    return 0;
}
// 1 *2 1 2 3 4 
// 4 3 *2 1 2 1

// 1 6 1
// 1 2 1 2 3 4 