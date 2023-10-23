#include <iostream>
#include <vector>
using namespace std;

vector < vector < int > > matrix_ago;
vector < vector < int > > matrix;
vector < int > new_people;

// 각 line 1 < 2 이면 t[i] = time
bool checkAround(int& person, int& n)
{
    int one = 0;
    int two = 0;

    // cout << "person : " << person << endl;

    for (int i = 0; i < n; i++) {
        if (matrix_ago[person][i] == 1) {
            one++;
            // new_people.push_back(i);
            // cout << person << ' ' << i << endl;
        } else if (matrix_ago[person][i] == 2) {
            two++;
        }
    }
    // for (int i = 0; i < new_people.size(); i++) {
    //     cout << new_people[i] << ' ';
    // }
    // cout << endl;
    // cout << "1,2 : " << one << ' ' << two << endl;

    return one <= two;
}


int main()
{
    ios :: sync_with_stdio(0);
    cin.tie(0);

    int n, m, num;
    int time = 0;
    vector < int > people;

    // n 받기
    cin >> n;
    vector < int > t(n, -1);
    for (int i = 0; i < n; i++) {
        // i번 사람의 주변인들의 번호 
        vector <int> v(n, 0);
        while (1) {
            cin >> num;
            if (num == 0)   break;
            v[num-1] = 1;
        }
        matrix.push_back(v);
    }

    // m 받기, m은 루머를 믿는다
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> num;
        people.push_back(num-1);
        for (int j = 0; j < n; j++) {
            if (matrix[j][num-1] == 1) {
                matrix[j][num-1] = 2;
            }
        }
        t[num-1] = 0;
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << matrix[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';

    // m 주변인 check -> m.clear -> 주변인을 m으로
    for (int time = 1; time <= n; time++) {
        matrix_ago.assign(matrix.begin(), matrix.end());
        for (int person : people) {
            // 주변 애들을 찾아
            for (int i = 0; i < n; i++) {
                // cout << "!!!!!" << person << ' ' << i << endl;
                if (matrix[person][i] == 1) {
                    if (checkAround(i, n) == true) {
                        for (int j = 0; j < n; j++) {
                            if (matrix[j][i] == 1) {
                                matrix[j][i] = 2;
                            }
                        }
                        t[i] = time;
                        new_people.push_back(i);
                    }
                }
            }
            // for (int i = 0; i < n; i++) {
            //     for (int j = 0; j < n; j++) {
            //         cout << matrix[i][j] << ' ';
            //     }
            //     cout << '\n';
            // }
            // cout << "time : " << time <<'\n';
        }
        people.clear();
        people.swap(new_people);
        // for (int i = 0; i < people.size(); i++) {
        //     cout << people[i] << ' ';
        // }
        // cout << ": people" << endl;
    }

    // time 출력
    for (int i = 0; i < n; i++) {
        cout << t[i] << ' ';
    }

    return 0;
}