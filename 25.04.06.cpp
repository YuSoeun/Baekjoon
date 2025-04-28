#include <bits/stdc++.h>
using namespace std;

struct Fruit
{
    int index;          // 과일 번호
    vector<int> order;  // 우선순위대로 정렬된 과일의 특징
};

struct
{
    bool operator()(Fruit x, Fruit y) {
        for (int i = 0; i < x.order.size(); i++) {
            if (x.order[i] != y.order[i])  return x.order[i] > y.order[i];
        }
        return x.index < y.index;   // 이건 호출될 일이 없다.
    }
} fCompare;

vector<int> solution(vector<vector<int>> fruits, vector<vector<int>> priority) {
    int N = fruits.size();
    vector<int> answer;
    vector<Fruit> reorderedFruits;

    for (int f = 0; f < N; f++) {
        auto &fruit = fruits[f];

        // 우선순위를 특징의 index로 변환하는 map
        unordered_map<int, int> m;
        for (int i = 0; i < fruit.size(); i++) {
            m[priority[f][i]] = i;          // priority[f][i]: 1부터 시작
        }
        
        Fruit newFruit;
        newFruit.index = f+1;
        for (int i = 1; i <= fruit.size(); i++) {
            newFruit.order.push_back(fruit[m[i]]);  
        }
        reorderedFruits.push_back(newFruit);
    }

    sort(reorderedFruits.begin(), reorderedFruits.end(), fCompare);
    for (auto& e : reorderedFruits) {
        // cout << "[" << e.index << "] ";
        // for (auto &k : e.order) cout << k << " ";
        // cout << "\n";
        answer.push_back(e.index);
    }

    return answer;
}