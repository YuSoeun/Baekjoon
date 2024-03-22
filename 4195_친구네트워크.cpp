#include <bits/stdc++.h>
using namespace std;

string a, b;
int a_type, b_type, type, type_cnt = 0;
map <string, int> rel; // relation
multimap <int, string> g_type; // graph_type
vector<int> cnt;

void rearrange_graph_type(int a_type, int b_type, int type) {
    if (a_type == -1 && b_type == -1) {
        type = ++type_cnt;  cnt.push_back(2);
        rel.insert(make_pair(a, type));
        rel.insert(make_pair(b, type));
        
        g_type.insert(make_pair(type, a));
        g_type.insert(make_pair(type, b));

        return;
    }

    // type 세팅
    int b_type_ago = b_type;
    if (b_type == -1)
        b_type = a_type;
    type = b_type;
    if (a_type < b_type)
        type = a_type;

    // cout << "a_type: " << a_type << endl;
    // cout << "b_type: " << b_type << endl;

    if (type == 0) {
        rel.insert(make_pair(a, type));
        rel.insert(make_pair(b, type));
        if (b_type_ago == -1) {
            cnt[type] += 1;
        } else {
            cnt[type] += 2;
        }

        return;
    }
    
    while (g_type.find(b_type) != g_type.end()) {
        cnt[b_type] --;  cnt[type]++;
        auto f = g_type.find(b_type);

        rel[f->second] = type;
        if (type == 0) {
            g_type.erase(f);
        }
    }
    if (type != 0) {
        auto nh = g_type.extract(b_type);
        nh.key() = type;
    }
}

int main()
{
    int T, F;

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> F >> a >> b;
        cout << 2 << "\n";
        rel.insert({make_pair(a, 0), make_pair(b, 0)});
        cnt.push_back(2);

        for (int j = 0; j < F-1; j++) {
            a_type = -1;  b_type = -1; type = -1;
            cin >> a >> b;
            // cout << "type: " << type << endl;
            // cout << "rel.size(): " << rel.size() << endl;
            // cout << "g_type.size(): " << g_type.size() << endl;

            if (auto s = rel.find(a); s != rel.end())
                a_type = s->second;
            if (auto s = rel.find(b); s != rel.end())
                b_type = s->second;
            // cout << endl;
            // cout << "a_type: " << a_type << endl;
            // cout << "b_type: " << b_type << endl;
            
            // a_type으로 바꾸려면
            if (a_type <= b_type || b_type == -1) {
                rearrange_graph_type(a_type, b_type, type);
            } else if (a_type >= b_type || a_type == -1) {
                // b_type으로 바꾸려면
                rearrange_graph_type(b_type, a_type, type);
            }
            
            // cout << "type: " << type << endl;
            // cout << "rel.size(): " << rel.size() << endl;
            // cout << "g_type.size(): " << g_type.size() << endl;

            // cout << "전체순회" << endl;
            // for (auto it = rel.begin(); it != rel.end(); it++)
            // {
            //     cout <<"["<< it->first <<","<< it->second <<"]"<< endl;
            // }

            int result = *max_element(cnt.begin(), cnt.end());
            cout << result << "\n";
        }

        rel.clear();  g_type.clear();  cnt.clear();
    }

    return 0;
}