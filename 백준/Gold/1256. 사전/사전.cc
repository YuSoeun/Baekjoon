#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define DATA long long
const int SIZE = 201;
const DATA MOD = 1000000007LL;

int N, M, K;
DATA combi[SIZE][SIZE];

void findKthString(int n, int m, int k, string &result) {
    if (n == 0) {
        result.append(m, 'z');
        return;
    }

    if (m == 0) {
        result.append(n, 'a');
        return;
    }

    DATA leftCount = combi[n - 1 + m][n - 1];
    // 현재 위치에 'a'를 두었을 때 만들 수 있는 문자열의 수가 k보다 같거나 많다면
    if (k <= leftCount) {
        result.push_back('a');
        findKthString(n - 1, m, k, result);
    } else {
        result.push_back('z');
        findKthString(n, m - 1, k - leftCount, result);
    }
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(0);
    cin >> N >> M >> K;

    fill(&combi[0][0], &combi[0][0] + SIZE * SIZE, 1);
    for (int i = 1; i < SIZE; i++) {
        for (int j = 1; j < i; j++) {
            combi[i][j] = combi[i-1][j-1] + combi[i-1][j];
            if (combi[i][j] > 1000000000) {
                combi[i][j] = 1000000001; // prevent overflow
            }
        }
    }

    if (combi[N+M][N] < K) {
        cout << "-1\n";
        return 0;
    }

    string result;
    findKthString(N, M, K, result);
    cout << result << "\n";

    return 0;
}