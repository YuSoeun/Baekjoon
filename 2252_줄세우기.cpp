#include <bits/stdc++.h>
using namespace std;

int n;      // N명의 학생
int m;      // 키를 비교한 회수

queue<int> topoloSort(vector<vector<int> > &matrix, vector<int> &indegrees)
{
    queue<int> result;
    
    // indegree 0인 것 만나면 queue에 넣기
    while (result.size() < n) {
        for (int i = 1; i < n+1; i++) {
            int value = indegrees[i];
            if (value == 0) {
                result.push(i);
                indegrees[i] = -1;
                
                // outdegree에 있는 에들 --
                for (int j : matrix[i]) {
                    indegrees[j]--;
                }
            }
        }
        if (result.size() >= n) {
            break;
        }
    }

    return result;
}

int main()
{
    int a, b;
    vector<int> indegrees;
    vector<vector<int> > matrix;

    cin >> n >> m;
    for (int i = 0; i < n+1; i++) {
        vector<int> temp;
        indegrees.push_back(0);
        matrix.push_back(temp);
    }

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        matrix[a].push_back(b);
        indegrees[b]++;
    }

    // for (int i : indegrees) {
    //     cout << i << " ";
    // }
    // cout << "------ indegrees ------" << endl;

    queue<int> result = topoloSort(matrix, indegrees);

    while (result.size() > 0) {
        cout << result.front() << " ";
        result.pop();
    }
    // cout << "------ result ------" << endl;

    return 0;
}