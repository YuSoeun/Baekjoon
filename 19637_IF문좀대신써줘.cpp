#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); ios::sync_with_stdio(0);
    int N, M;

    cin >> N >> M;
    vector<string>    names(N);      // 이름
    vector<int> max_powers(N); // 전투력 상한값

    for (int i = 0; i < N; i++) {
        cin >> names[i];
        cin >> max_powers[i];
    }

    //n^2 안돼서 n log(n) 사용
    int num;
    for (int i = 0; i < M; i++) {
        cin >> num;
        
        // num-1로 한건 num도 포함하려
        auto upper = upper_bound(max_powers.begin(), max_powers.end(), num-1);
        auto index = distance(max_powers.begin(), upper);

        cout << names[index] << "\n";
    }

    return 0;
}