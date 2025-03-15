#include <bits/stdc++.h>
using namespace std;

int N, M;
string ret[] = {"Equilateral", "Isosceles", "Scalene", "Invalid"};
int lens[3];

void split(string &s) {
    istringstream ss(s);
    string sub;

    int i = 0;
    while (ss >> sub) {
        lens[i++] = stoi(sub);
    }
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(0);
    
    string input;
    vector<int> v(3);
    while (getline(cin, input)) {
        split(input);
        int maxLen = 0;
        int sum = 0;
        for (int i = 0; i < 3; i++) {
            maxLen = max(lens[i], maxLen);
            sum += lens[i];
        }
        if (lens[0] == 0)   break;

        int type = 0;
        if (maxLen >= sum-maxLen) {
            type = 3;
        } else if (lens[0] == lens[1] && lens[1] == lens[2]) {
            type = 0;
        } else if (lens[0] == lens[1] || lens[1] == lens[2] || lens[0] == lens[2]) {
            type = 1;
        } else {
            type = 2;
        }
        cout << ret[type] << "\n";
    }

    return 0;
}