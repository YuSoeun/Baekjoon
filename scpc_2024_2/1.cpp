
/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <bits/stdc++.h>
using namespace std;

int Answer;

void printVector(vector<int> a)
{
    for (int e : a) {
        cout << e << " ";
    }
    cout << "\n";
}

int main(int argc, char** argv)
{
    cin.tie(0); ios::sync_with_stdio(0);
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

	// freopen("input.txt", "r", stdin);

	cin >> T;
	int N, S, E;
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		/////////////////////////////////////////////////////////////////////////////////////////////
		vector <int> zero, one;
        int zero_cnt = 0, one_cnt = 0, num;
        int start_zero_flag = 0;
        cin >> N >> S >> E;

        for (int j = 0; j < N; j++) {
            cin >> num;

            // 0으로 시작하면 1 나올때까지 continue
            if (j == 0 && num == 0)
                start_zero_flag = 1;

            if (start_zero_flag == 1 && num == 0) {
                continue;
            } else if (start_zero_flag == 1 && num == 1) {
                start_zero_flag = 0;
            }

            if (num == 0) {
                if (one_cnt > 0)
                    one.push_back(one_cnt);
                zero_cnt++;
                one_cnt = 0;
            } else {
                if (zero_cnt > 0)
                    zero.push_back(zero_cnt);
                one_cnt++;
                zero_cnt = 0;
            }
        }
        if (one_cnt > 0)
            one.push_back(one_cnt);
        if (zero_cnt > 0)
            zero.push_back(zero_cnt);

        // printVector(one);
        // printVector(zero);

        int left = 0;
        int right = one.size() - 1;
        int left_fix = 0, right_fix = 0;
        // int Answer = 0;
        while (left < right && (left_fix == 0 && right_fix == 0)) {
            if (left_fix == 0) {
                if (one[left] * E > zero[left] * S) {
                    // 0을 1로
                    Answer += zero[left] * S;
                    zero[left] = 0;                 // for checking
                    left_fix = 1;
                } else {
                    Answer += one[left] * E;
                    one[left] = 0;
                }
                left++;
            }

            if (right_fix == 0) {
                if (one[right] * E > zero[right-1] * S) {
                    // 0을 1로
                    Answer += zero[right-1] * S;
                    zero[right-1] = 0;
                    right_fix = 1;
                } else {
                    Answer += one[right] * E;
                    one[right] = 0;
                }
                right--;
            }

            // printVector(one);
            // printVector(zero);
            // cout << "\n";
        }

        if (left_fix == 1 && right_fix == 1) {
            // cout << "here!" << "\n";
            // 사이 0들 다 더하기
            while (left < right) {
                Answer += zero[left] * S;
                left++;
            }
        }
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}