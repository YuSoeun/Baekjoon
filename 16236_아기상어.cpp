#include <bits/stdc++.h>
using namespace std;

int main() {
    priority_queue<pair<int, int> > pq;
    vector <vector<int> >  matrix;
    int n;
    vector <int> one;
    vector <int> two;
    vector <int> three;
    vector <int> four;
    vector <int> five;
    vector <int> six;

    pair<int, int> cur;

    cin >> n;

    for (int i = 0; i < n; i++) {
        vector<int> v(n);
        matrix.push_back(v);
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
            int value = matrix[i][j];

            switch (value) {
                case 1:
                    one.push_back(value);
                    break;
                case 2:
                    two.push_back(value);
                    break;
                case 3:
                    three.push_back(value);
                    break;
                case 4:
                    four.push_back(value);
                    break;
                case 5:
                    five.push_back(value);
                    break;
                case 6:
                    six.push_back(value);
                    break;
                case 9:
                    cur = make_pair(j, i);
                default:
                    break;
            }
        }
    }
}