#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
    cin.tie(0); ios::sync_with_stdio(0);

    unordered_map <string, int> name2Index;
    vector <string> Index2Name(1, "first");
    int N, M;
    cin >> N >> M;
    
    string poket;
    for (int i = 1; i <= N; i++) {
        cin >> poket;
        Index2Name.push_back(poket);
        name2Index[poket] = i;
    }

    string quest;
    for (int i = 1; i <= M; i++) {
        cin >> quest;
        if (name2Index.count(quest) == 0) {
            cout << Index2Name[stoi(quest)] << "\n";
        } else {
            cout << name2Index[quest] << "\n";
        }
    }

    return 0;
}