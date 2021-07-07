/*
문제
N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.

입력
첫째 줄에 수의 개수 N(1 ≤ N ≤ 1,000)이 주어진다. 둘째 줄부터 N개의 줄에는 숫자가 주어진다. 이 수는 절댓값이 1,000보다 작거나 같은 정수이다. 수는 중복되지 않는다.

출력
첫째 줄부터 N개의 줄에 오름차순으로 정렬한 결과를 한 줄에 하나씩 출력한다.


*/

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int main()
{
    ios :: sync_with_stdio(0);
    cin.tie(0);

    int n;
    vector <int> num;

    cin >> n;
    int temp;

    for (int i = 0; i < n; i++) {
        cin >> temp;
        num.push_back(temp);
    }

    sort(num.begin(), num.end());

    for (int i = 0; i < n; i++) {
        cout << num[i] << endl;
    }

    return 0;
}