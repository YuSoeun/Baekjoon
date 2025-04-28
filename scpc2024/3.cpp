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
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */	

	freopen("input3.txt", "r", stdin);

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
        int N, a, b;
		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		/////////////////////////////////////////////////////////////////////////////////////////////
		cin >> N;
        vector<int> v(N+1, 0);
        for (int i = 0; i < N+1; i++) {
            cin >> a >> b;
            v[a]++;
            v[b]++;
        }

		int index = 0;
		vector<int> contin(1, 0);
		// 간선 2개인 것, 연속인 것 세기
        for	 (int i = 1; i < N+1; i++) {
			// cout << "i: " << i << ", value: " << v[i] << endl;
			if (v[i] == 3){
				index++;
				contin.push_back(0);
			}
            if (v[i] <= 2) {
				contin[index]++;
                Answer++;
            }
        }
		if (v[N] == 2) {
			contin[0] += contin[index];
			contin[index] = 0;
		}

		if (N >= 5) {
			// n개 연속인 것에 따라 Answer++;
			for (int e : contin) {
				// cout << "e: " << e << endl;
				for (int i = 2; i <= e; i++) {
					// cout << "Answer: " << Answer << endl;
					Answer += e-i + 1;
				}
			}
		}

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}