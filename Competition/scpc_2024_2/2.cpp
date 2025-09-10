/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <bits/stdc++.h>
using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case;

	freopen("sample_input22.txt", "r", stdin);

    int N, Q, temp, X;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++) {
		Answer = 0;
		
        cin >> N >> Q;
        vector<pair<int, int> > W;
        int i = 0;
        int pre_i = i;

        for (int i = 0; i < N; i++) {
            cin >> temp;
            W.push_back({temp, i});
        }
        sort(W.begin(), W.end());

        for (int q = 0; q < Q; q++) {
            cin >> X;
            i = 0; pre_i = 0;

            int remain_n = N;       // 남은 개수
            // cout << "i: " << i << ", X: "  << X << ", N: " << N << ", remain_n: " << remain_n << endl;
            while (1) {
                int pre_values = 0;
                while (i < N-1) {
                    // 같기 전에 멈추기
                    if (X/remain_n < W[i].first)
                        break;
                    
                    pre_values += W[i].first;
                    i++;
                }
                X -= pre_values;
                remain_n -= abs(i - pre_i);
                // cout << "i: " << i << ", X: "  << X << ", N: " << N << ", remain_n: " << remain_n << endl;
                if (pre_i == i)
                    break;
                pre_i = i;
            }

            vector <pair<int, int> > values;
            // vector 특정 범위 뒤에 value 중에 X번째 print
            for (int k = i; k < N; k++) {
                values.push_back({W[k].second, W[k].first});
            }
            sort(values.begin(), values.end());
            // cout << "values[X%remain_n]: " <<  values[X%remain_n - 1].second << "\n";
            Answer += values[X%remain_n - 1].second;
        }

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0; //Your program should return 0 on normal termination.
}