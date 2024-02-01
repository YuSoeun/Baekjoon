#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    char temp, ch;
    vector <int> left, right;
    vector <int> index_0, index_1, index_2;

    cin >> n >> k;

    int size = n/2;
    for (int i = 0; i < n; i++) {
        cin >> temp;

        if (i < size) {
            if (temp == '2') {
                left.push_back(0);
            } else if (temp == '3') {
                left.push_back(1);
            } else if (temp == 'E') {
                left.push_back(2);
            }
        } else {
            if (temp == '2') {
                // index_0.push_back(i-size);
                right.push_back(0);
            } else if (temp == '3') {
                // index_2.push_back(i-size);
                right.push_back(2);
            } else if (temp == 'E') {
                // index_1.push_back(i-size);
                right.push_back(1);
            }
        }
    }

    for (const int e : left)
        std::cout << e << ' ';
    for (const int e : right)
        std::cout << e << ' ';
    cout << endl;

    int beauti = 0;

    for (int i = 0; i < size; i++) {
        if (left[i] == right[size-i-1]) {
            left.erase(left.begin() + i);
            right.erase(right.begin() + size - i - 1);
            i--; size--;
            beauti += 2;
        }
    }
    
    for (const int e : left)
        std::cout << e << ' ';
    for (const int e : right)
        std::cout << e << ' ';
    cout << endl;
    cout << beauti << endl;

    for (int i = 0; i < k; i++) {
        if (beauti == n) {
            cout << beauti << "\n";
            break;
        }
        vector <int> index;
        for (int j = 0; j < size; j++) {
            if (left[j] == right[j]) {
                index.push_back(j);
            }
        }

        if (index.size() >= 2) {
            left.erase(left.begin() + index[1]);  right.erase(right.begin() + index[1]);
            left.erase(left.begin() + index[0]);  right.erase(right.begin() + index[0]);
            beauti += 4;
            size -= 2;
        } else if (index.size() == 1) {
            left.erase(left.begin() + index[0]);  left.erase(right.begin() + index[0]);
            beauti += 2;
            size -= 1;
        }

        // beauti 재검사
        for (int k = 0; k < size; k++) {
            if (left[k] == right[size-k-1]) {
                left.erase(left.begin() + k);
                right.erase(right.begin() + size - k - 1);
                k--; size--;
                beauti += 2;
            }
        }

        cout << beauti << "\n";
    }

    // for (const int e : left)
    //     std::cout << e << ' ';
    // for (const int e : right)
    //     std::cout << e << ' ';
    
    // cout << endl;
    // cout << beauti << endl;

    return 0;
}