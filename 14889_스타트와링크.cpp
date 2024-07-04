#include <bits/stdc++.h>
using namespace std;
int N;
vector<vector<int> > M;

void printMatrix()
{
    cout << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
}

/* start와 link간 차 계산*/
int getMinus(vector<int> &s, vector<int> &l)
{
    int start = 0;
    int link = 0;

    for (int i = 0; i < N/2; i++) {
        for (int j = i+1; j < N/2; j++) {
            start += M[s[i]][s[j]];
        }
    }

    for (int i = 0; i < N/2; i++) {
        for (int j = i+1; j < N/2; j++) {
            link += M[l[i]][l[j]];
        }
    }

    return abs(start-link);
}

/* N개에서 N/2개 배열 뽑기 */
int makeSequnce(vector<int>s, vector<int>l, int index) {
    /* 둘 중 하나가 가득 차면 다른것만 넣고 차 구하기 */
    if (s.size() == N/2) {
        for (int i = l.size(); i < N/2; i++) {
            l.push_back(index++);
        }
        return getMinus(s, l);
    }
    
    if (l.size() == N/2) {
        for (int i = s.size(); i < N/2; i++) {
            s.push_back(index++);
        }
        return getMinus(s, l);
    }
    
    l.push_back(index);
    int a = makeSequnce(s, l, index+1);
    l.pop_back();

    s.push_back(index);
    int b = makeSequnce(s, l, index+1);
    s.pop_back();
    // cout << "a: " << a << ", b: " << b << endl;

    if (a == -1 || (a > b && b != -1))  return b;
    return a;
}

int main()
{
    int temp;

    cin >> N;

    for (int i = 0; i < N; i++) {
        vector<int> m(N, 0);
        M.push_back(m);
        for (int j = 0; j < N; j++) {
            cin >> temp;
            if (j > i) {
                M[i][j] += temp;
            } else {
                M[j][i] += temp;
            }
        }
    }

    vector<int>s;  vector<int>l;
    cout << makeSequnce(s, l, 0) << "\n";

    return 0;
}