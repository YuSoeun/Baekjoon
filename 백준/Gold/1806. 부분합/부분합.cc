#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

int N, S;
vector<int> matrix;

// 0과 관련한 테스트 케이스가 주요하다

int main()
{
    cin.tie(0); ios::sync_with_stdio(0);
    cin >> N >> S;
    matrix.assign(N+1, 0);

    for (int i = 1; i <= N; i++) {
        cin >> matrix[i];
    }

    // 누적합 구하기
    for (int i = 1; i <= N; i++) {
        matrix[i+1] = matrix[i] + matrix[i+1];
    }
    
    int result = INT_MAX;
    int start = 0, end = 1;
    while (end <= N) {
        int diff = matrix[end] - matrix[start];
        
        // S가 0인 경우 예외 처리
        if (diff >= S && diff != 0) {
            result = min((int)end-start, result);
            start++;
        } else {
            end++;
        }

        if (start == end)  end++;
    }

    if (result == INT_MAX) {
        cout << "0\n";
    } else {
        cout << result << "\n";
    }

    return 0;
}