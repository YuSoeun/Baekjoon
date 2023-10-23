/*
n가지 종류의 동전이 있다. 이 동전들을 적당히 사용해서, 그 가치의 합이 k원이 되도록 하고 싶다. 그러면서 동전의 개수가 최소가 되도록 하려고 한다. 각각의 동전은 몇 개라도 사용할 수 있다.

사용한 동전의 구성이 같은데, 순서만 다른 것은 같은 경우이다.

입력
첫째 줄에 n, k가 주어진다. (1 ≤ n ≤ 100, 1 ≤ k ≤ 10,000) 다음 n개의 줄에는 각각의 동전의 가치가 주어진다. 동전의 가치는 100,000보다 작거나 같은 자연수이다. 가치가 같은 동전이 여러 번 주어질 수도 있다.

출력
첫째 줄에 사용한 동전의 최소 개수를 출력한다. 불가능한 경우에는 -1을 출력한다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int matrix[100001];

int countCoin(vector<int> &values, int n, int k)
{
    int min_sum = 100001;

    if (k == 0) {
        return 0;
    } else if (k < 0) {
        return -1;
    } else {
        if (matrix[k] > 0) {
            return matrix[k];
        }

        for (int i = 0; i < n; i++) {
            int temp = countCoin(values, n, k - values[n-i-1]) + 1;
            if (temp < min_sum && temp != 0) {
                min_sum = temp;
            }
        }
        matrix[k] = min_sum;
        return min_sum;
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, k, temp;
    cin >> n >> k;

    vector<int> values;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        values.push_back(temp);
    }
    sort(values.begin(), values.end());

    int sum = countCoin(values, n, k);
    if (sum == 100001) {
        cout << -1 << "\n";
    } else {
        cout << sum << "\n";
    }

    return 0;
}