#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100; // maximum number of vertices
int n; // number of vertices
vector<int> g[MAXN]; // adjacency list of the graph
int clique[MAXN]; // current clique
bool used[MAXN]; // whether a vertex is used in the current clique

void find_cliques(int pos, int size) {
    if (size == 15) {
        // print the clique
        for (int i = 0; i < size; i++) {
            cout << clique[i] << " ";
        }
        cout << endl;
        return;
    }
    for (int i = pos; i < n; i++) {
        if (used[i]) continue;
        bool ok = true;
        for (int j : g[clique[size - 1]]) {
            if (j == i) continue;
            if (!used[j]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            clique[size] = i;
            used[i] = true;
            find_cliques(i + 1, size + 1);
            used[i] = false;
        }
    }
}

int main() {
    int m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 0; i < n; i++) {
        clique[0] = i;
        used[i] = true;
        find_cliques(i + 1, 1);
        used[i] = false;
    }
    return 0;
}