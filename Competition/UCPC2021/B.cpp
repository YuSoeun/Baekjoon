#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios :: sync_with_stdio(0);
    cin.tie(0);

    int n, m, num, save;
    vector < vector < int > > matrix_ago;
    vector < vector < int > > matrix_new;

    // n 받기
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        vector <int> v;
        for (int j = 0; j < m; j++) {
            cin >> num;
            v.push_back(num);
        }
        matrix_ago.push_back(v);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix_ago[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';


    for (int i = 0; i < n; i++) {
        vector <int> v;
        for (int j = 0; j < m; j++) {
            cin >> num;
            if (matrix_ago[i][j] - num != 0) {
                v.push_back(num - 1);
                save = matrix_ago[i][j];
            } else {
                v.push_back(num);
            }
        }
        matrix_new.push_back(v);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix_new[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix_ago[i][j] != matrix_new[i][j]) {
                cout << "NO" << '\n';
                return 0;
            }
        }
    }

    cout << "YES" << '\n';
    return 0;
}