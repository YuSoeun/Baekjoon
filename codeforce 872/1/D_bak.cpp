#include <iostream>
#include <vector>
using namespace std;

vector <int> a;
vector <int> q;
int getXfromFuction(int l, int r, int j);

int main()
{
    ios :: sync_with_stdio(0);
    cin.tie(0);
    int n;           // length of the array a
    int q;           // the number of queries

    cin >> n >> q;
    int temp = 0;
    a.push_back(temp);      // dummy

    for (int i = 0; i < n; i++) {
        cin >> temp;
        a.push_back(temp);
    }

    int l, r, x, y;
    for (int line = 0; line < q; line++) {
        int result = 0;
        cin >> l >> r >> x >> y;

        for (int j = x ; j <= y; j++) {
        // for (int i = l ; i <= r; i++) {
            // for (int j = x ; j <= y; j++) {
            //     // cout << "i: " << i <<  ", j: " << j << endl;
            //     result += getXfromFuction(i, j);
            // }
            result += getXfromFuction(l, r, j);
        }  
        cout << result << "\n";
    }

    return 0;
}

int getXfromFuction(int l, int r, int j)
{
    vector <int> element;
    int result = 0;
    int index = j;

    // 뒤에서부터 안 겹치는 거 찾기
    for (int x = j ; x >= l; x--) {
        if (x > j)  return 0;
        // cout << "a" << x << ": " << a[x] << endl;
        if (find(element.begin(), element.end(), a[x]) != element.end()) {
            // 겹치는 거
        } else {
            // 안 겹치는 거
            index = x;
            // cout << "index: " << index << "\n";
        }
        if (x <= r) {
            result += index;
        }
        element.push_back(a[x]);

        // cout << "j: " << j << ", i: " << x << ", index: " << index << endl;
    }

    return result;
}

// int getXfromFuction(int i, int j)
// {
//     vector <int> element;
//     int index = i;
//     if (i > j)  return 0;

//     // 뒤에서부터 안 겹치는 거 찾기
//     for (int x = j ; x >= i; x--) {
//         // cout << "a" << x << ": " << a[x] << endl;
//         if (find(element.begin(), element.end(), a[x]) != element.end()) {
//             // 겹치는 거
//         } else {
//             index = x;
//             // cout << "index: " << index << "\n";
//             // 안 겹치는 거

//         }
//         element.push_back(a[x]);
//     }

//     // cout << "j: " << j << ", i: " << i << ", index: " << index << endl;
//     g[i][j] = index;

//     return index;
// }