#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int t, flag;
    char temp;
    
    string input;

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    for (int i = 0; i < t; i++) {
        stack<char> array;
        flag = 0;
        cin >> input;
        for (int e : input) {
            if (e == '(') {
                array.push(e);
            } else if (e == ')') {
                if (array.size() > 0) {
                    array.pop();
                } else {
                    flag = 1;
                }
            }
        }

        if (array.empty() && flag == 0) {
        cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}