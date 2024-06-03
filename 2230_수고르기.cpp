#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> v;

int getMinDiffer(int min, int left, int right)
{
    // cout << "left: " << left << ", right: " << right << ", min: " << min << endl;
    if (left >= right || right >= n)
        return min;

    int differ = abs(v[right] - v[left]);

    if (differ >= m && min > differ)
        min = differ;

    if (differ < m) {
        min = getMinDiffer(min, left, right+1);
    } else {
        min = getMinDiffer(min, left+1, right);
    }

    return min;
}

int main()
{
    int temp;
    int ago = 0;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end());

    int left = 0, right = 1;

    int min = INT_MAX;

    cout << getMinDiffer(min, left, right) << "\n";

    return 0;
}