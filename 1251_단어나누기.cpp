#include <bits/stdc++.h>
using namespace std;

int main()
{
    string word;
    vector <string> results;

    cin >> word;
    
    for (int i = 1; i < word.size() - 1; i++) {
        
        for (int j = 1; j < word.size()-i; j++) {
            string result;
            deque<char> temp;
            for (int k = 0; k < word.size(); k++) {
                if (k == j || k == j + i) {
                    // cout << "k: " << k << endl;
                    for (char c : temp)
                        result.push_back(c);
                    temp.clear();
                }
                temp.push_front(word[k]);
            }
            for (char c : temp)
                result.push_back(c);
            
            // cout << result << "\n";
            results.push_back(result);
        }
    }
    sort(results.begin(), results.end());

    cout << results[0] << "\n";

    return 0;
}