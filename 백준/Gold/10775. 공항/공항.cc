#include <bits/stdc++.h>
using namespace std;

int G, P, maxGate;
vector <int> g;
vector <int> visited;

void printVector(vector<int> &v) {
    cout << "g: ";
    for (auto e : v) {
        cout << e << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> G >> P;
    g.assign(G+1, 0);
    visited.assign(G+1, 0);
    for (int i = 0; i <= g.size(); i++) {
        g[i] = i;
    }

    int cnt = 0;
    int flag = true;
    for (int i = 0; i < P; i++) {
        cin >> maxGate;

        if (!visited[maxGate]) {
            visited[maxGate] = 1;
            g[maxGate] = maxGate;
        } else {
            int idx;
            while (1) {
                idx = lower_bound(g.begin(), g.end(), maxGate) - g.begin();
                idx--;
                if (idx >= maxGate || idx <= 0) {
                    flag = false;
                    break;
                }
                if (visited[idx]) {
                    maxGate--;
                } else {
                    break;
                }
            }
            
            if (flag) {
                visited[idx] = 1;
                g[idx] = maxGate;
            }
        }
        if (flag)  cnt++;
    }

    cout << cnt << "\n";

    return 0;
}