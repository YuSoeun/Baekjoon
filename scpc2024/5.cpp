/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <bits/stdc++.h>

using namespace std;

int Answer;

/* ㆍ 그룹 1 (128점) : 이 그룹의 테스트 케이스에서는 Q≤100이다. */

int main(int argc, char** argv)
{
	int T, test_case;
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */	

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
	freopen("input6.txt", "r", stdin);

    clock_t start, finish;

    start = clock();

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        int N, temp;
        int L, R, Q;
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		/////////////////////////////////////////////////////////////////////////////////////////////
		cin >> N;
        vector <int> v(N);
        for (int i = 0; i < N; i++) {
            cin >> v[i];
        }

        cin >> Q;
		cout << "Case #" << test_case+1 << endl;
        for (int k = 0; k < Q; k++) {
            cin >> L >> R;
            map<int, int> M;
		    Answer = 0;
            L--; R--;

            for (int i = L; i <= R; i++) {
                if (auto search = M.find(v[i]); search != M.end()) {
                    M[v[i]]++;
                } else {
                    M[v[i]] = 1;
                }
            }

            /* for condition from cppreference */
            for (const auto& [key, value] : M) {
                if (key == 1)
                    continue;
                // cout << "[" << key << "]: " << value << " ";
                
                while (key <= value) {
                    M[key] -= key;
                    Answer++;
                    temp = key*key;

                    if (key <= 10000) {
                        if (auto search = M.find(temp); search != M.end()) {
                            M[temp]++;
                        } else {
                            M[temp] = 1;
                        }
                    }
                }
            }
            cout << Answer << endl;
        }
	}

    finish = clock();
    cout << (double) (finish - start) / CLOCKS_PER_SEC << endl;

	return 0;//Your program should return 0 on normal termination.
}