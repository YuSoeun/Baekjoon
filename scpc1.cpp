/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include<cstdio>
#include <vector>

using namespace std;

vector<vector<int> > edge;
vector<bool> visited;
int Answer;
int N, M;
int u, v;

void dfs(int cur) {
    visited[cur] = true;
    // cout << cur+1 << ' ';
    for (int i = 0; i < (int)edge[cur].size(); i++) {
        int there = edge[cur][i];
        if (visited[there]) continue;
        dfs(there);
    }
}

int main(int argc, char** argv)
{
	int T, N, test_case;
	int num;

	// freopen("input.txt", "r", stdin);

	cin >> T;
	for (test_case = 0; test_case < T; test_case++) {
		Answer = 0;
		
		cin >> N;
		edge.resize(N + 1);
    	visited.resize(N + 2);

		visited[N] = true;

		for (int i = 0; i < N; i++) {
			cin >> num;
			if (i + num < N) {
				edge[i].push_back(i + num);
				edge[i+num].push_back(i);
			} else {
				// visited[N]은 이미 true
				edge[i].push_back(N);
			}
		}
		
		for (int i = 0; i < N; i++) {
			if (!visited[i]) {
				dfs(i);
				// cout << endl;
				Answer++;
			}
			
		}
		
		edge.clear();
		visited.clear();
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}