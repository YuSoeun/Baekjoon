#include <bits/stdc++.h>
using namespace std;

// https://school.programmers.co.kr/learn/courses/30/lessons/258712

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    map<string, int> gift_factor;
    map<pair<string, string>, int> gift;
    
    int N = friends.size();
    
    for (auto e : gifts) {
        stringstream ss(e);
        string left, right;
        ss >> left >> right;
        
        gift_factor[left]++;    gift_factor[right]--;
        gift[make_pair(left, right)]++;
    }
    
    vector<int> result(N, 0);
    for (int i = 0; i < N; i++) {
        string f1 = friends[i];
        for (int j = i+1; j < N; j++) {
            string f2 = friends[j];
            int diff = gift[make_pair(f1, f2)] - gift[make_pair(f2, f1)];
            if (diff > 0) {
                result[i]++;
            } else if (diff < 0) {
                result[j]++;
            } else if (gift_factor[f1] > gift_factor[f2]) {
                result[i]++;
            } else if (gift_factor[f1] < gift_factor[f2]) {
                result[j]++;
            }
        }
    }
    
    answer = *max_element(result.begin(), result.end());
    
    return answer;
}