#include <bits/stdc++.h>
using namespace std;

vector<int> parent;

/* 대표 노드 반환 */
int find(int a)
{
    if (a == parent[a]) {
        return a;
    } else {
        // 이게 시간을 줄여주네
        return parent[a] = find(parent[a]);
    }
}

/* a와 b의 대표 노드를 같게 */
void make_union(int a, int b)
{
    int first = find(a);
    int second = find(b);

    if (first != second)
        parent[second] = first;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, m;

    cin >> n >> m;
    for (int i = 0; i <= n; i++) {
        parent.push_back(i);
    }

    int method, a, b;
    for (int i = 0; i < m; i++) {
        cin >> method >> a >> b;

        if (method == 0) {
            make_union(a, b);
        } else if (method == 1) {
            if (find(a) == find(b)){
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
        // int count = 0;
        // for (int i : parent) {
        //     cout << "(" << count++ << ")";
        //     cout << i << " ";
        // }
        // cout << endl;
    }


    return 0;
}