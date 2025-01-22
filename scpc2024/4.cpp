/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

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

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	freopen("input4.txt", "r", stdin);

	cin >> T;
	int N, L;
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 0;
		cin >> N >> L;
		vector<int> A(N), B(N);

		for (int i = 0; i < N; i++)
			cin >> A[i];
		for (int i = 0; i < N; i++)
			cin >> B[i];
		sort(A.begin(), A.end());
		sort(B.begin(), B.end());

		int max = -1;
		vector<pair<int, int>> max_set;
		
		// search b - a
		int a = 0, b = 0;
		while (a < N && b < N) {
			int value = abs(B[b] - A[a]);
			if (value > L) {
				a++;
			} else {
				if (value > max) {
					max = value;
					max_set.clear();
					max_set.push_back(make_pair(a,b));
				} else if (value == max) {
					max_set.push_back(make_pair(a, b));
				}
				b++;
			}
		}

		// search a - b
		a = 0, b = 0;
		while (a < N && b < N) {
			int value = abs(A[a] - B[b]);
			if (value > L) {
				b++;
			} else {
				if (value > max) {
					max = value;
					max_set.clear();
					max_set.push_back(make_pair(a,b));
				} else if (value == max) {
					max_set.push_back(make_pair(a, b));
				}
				a++;
			}
		}

		// for (const auto& [x, y] : max_set) {
		// 	cout << "max: " << max << " (" << x << ", " << y << ")" << endl;
		// }

		int diff_max_min = INT_MAX;
		for (const auto& [x, y] : max_set) {
			int diff_max = -1, diff;
			for (int i = 0, j = 0; i < N; i++, j++) {
				if (i == x)	i++;
				if (j == y) j++;
				// cout << "A[" << i << "]: " << A[i] << " ";
				// cout << "B[" << j << "]: " << B[j] << endl;

				diff = abs(A[i] - B[j]);
				if (diff > diff_max) {
					diff_max = diff;
				}
			}

			if (diff_max < diff_max_min && diff_max != -1) {
				diff_max_min = diff_max;
			}
		}

		if (diff_max_min > L) {
			Answer = -1;
		} else {
			Answer = max;
		}

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}