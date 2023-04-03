#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

bool isClique(vector<vector<int> >& graph, vector<int>& vertices) {
    for (int i = 0; i < vertices.size(); i++) {
        for (int j = i+1; j < vertices.size(); j++) {
            if (!graph[vertices[i]][vertices[j]]) {
                return false;
            }
        }
    }
    return true;
}

int maxCliqueSize(vector<vector<int> >& graph, int n) {
    int maxClique = 0;
    for (int i = 1; i < (1 << n); i++) {
        vector<int> vertices;
        for (int j = 0; j < n; j++) {
            if ((i & (1 << j)) != 0) {
                vertices.push_back(j);
            }
        }
        if (isClique(graph, vertices)) {
            maxClique = max(maxClique, (int) vertices.size());
        }
    }
    return maxClique;
}

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    vector<vector<int> > graph(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = (i*n + j + 1) % 3;
        }
    }

    clock_t start = 0, stop = 0;
	double duration = 0;
	start = clock();

    int maxClique = maxCliqueSize(graph, n);

    stop = clock();
	duration = (double) (stop - start) / CLOCKS_PER_SEC;

    cout << "The maximum clique size is: " << maxClique << endl;
    cout << "Time elapsed is " << duration << "seconds" << endl;

    return 0;
}