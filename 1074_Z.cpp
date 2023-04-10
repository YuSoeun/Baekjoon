/*
    한수는 크기가 2N × 2N인 2차원 배열을 Z모양으로 탐색하려고 한다.
    예를 들어, 2×2배열을 왼쪽 위칸, 오른쪽 위칸, 왼쪽 아래칸, 오른쪽 아래칸 순서대로 방문하면 Z모양이다.
    N > 1인 경우, 배열을 크기가 2N-1 × 2N-1로 4등분 한 후에 재귀적으로 순서대로 방문한다.

    입력
    첫째 줄에 정수 N, r, c가 주어진다.

    출력
    r행 c열을 몇 번째로 방문했는지 출력한다.

*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int visitCounter(int n, int row, int column, int count);

int main()
{
    ios :: sync_with_stdio(0);
    cin.tie(0);
    int n, row, column;

    cin >> n >> row >> column;

    cout << visitCounter(n, row, column, 0) << endl;

    return 0;
}

int visitCounter(int n, int row, int column, int count)
{
    int temp = 0, size = pow(2, n);
    int right = 0, up = 0;
    int block = pow(4, (n-1));
    
    if (column >= size/2)  right = 1;   // r이 오른쪽인지
    if (row >= size/2)  up = 1;          // c가 위인지

    // count 값 구하기
    if (right == 1)  temp++;
    if (up == 1)  temp += 2;
    if (size/2 > 1) {
        count += block * temp;
    }

    int result = count + temp;

    // cout << "row: " << row << ", column: " << column << ", block: " << block << endl;
    // cout << "size: " << size << ", right: " << right << ", up: " << up << endl;
    // cout << "count: " << count << ", temp: " << temp << ", result: " << result << endl;

    if (n <= 1) {
        return result;
    } else {
        row = row - (size/2)*up;
        column = column - (size/2)*right;
        result = visitCounter(n-1, row, column, count);
    }

    return result;
}