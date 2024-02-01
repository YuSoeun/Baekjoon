#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    string name, command;
    map<string, int> cur;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> name >> command;
        if (command == "enter") {
            cur.insert(make_pair(name, 1));
        } else if (command == "leave") {
            cur.erase(name);
        }
    }
    vector<string> s;

    for (const auto& [key, value] : cur)
        s.push_back(key);

    for (string item : s)
        cout << item << "\n";

    return 0;
}