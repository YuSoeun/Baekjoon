#include <iostream>
#include <vector>
#include <algorithm>
#define DATA long long
using namespace std;

struct Meeting {
    DATA s;
    DATA e;
};

int N;
vector<Meeting> meetings;

struct {
    bool operator()(Meeting m1, Meeting m2) {
        if (m1.e == m2.e)   return m1.s < m2.s;
        return m1.e < m2.e;
    }
} myCompare;

int main(int argc, char const *argv[]) {
    cin >> N;

    DATA start, end;
    for (int i = 0; i < N; i++) {
        cin >> start >> end;
        meetings.push_back({start, end});
    }
    sort(meetings.begin(), meetings.end(), myCompare);
    
    int result = 0;
    end = 0;
    for (auto m : meetings) {
        if (m.s >= end) {
            result++;
            end = m.e;
        }
    }

    cout << result << "\n";

    return 0;
}