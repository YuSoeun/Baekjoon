#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int input_size = points.size();
        int result = 1;
        double ax, ay, temp;
        double gradient = 0.0;

        // stardard_point와 다른 점들과의 기울기 찾고, 기울기 같은 거 count
        for (int i = 0; i < input_size-1; i++) {
            int max_count = 1;
            map<double, int> gradients = {};
            int x_zero = 0;

            vector<int>& standard_point = points[i];

            for (int j = i+1; j < input_size; j++) {
                cout << standard_point[0] << " " << standard_point[1] << endl;
                cout << points[j][0] << " " << points[j][1] << endl;
                ax = points[j][0] - standard_point[0];
                ay = points[j][1] - standard_point[1];
                if (ax == 0) {
                    x_zero++;
                    break;
                } else if (ay == 0) {
                    gradient = 0;
                } else {
                    gradient = ay/ax;
                }
                cout << "gradient: " << gradient << endl;
                auto search = gradients.find(gradient);
                if (search != gradients.end()) {
                    search->second++;
                    cout << "search[0]: " << search->first << ", search[1]: " << search->second << endl;
                    // if (search->second + 1 > max_count)
                    //     max_count = search->second + 1;
                    //     cout << "max_count: " << max_count << endl;
                } else {
                    gradients.insert(pair{gradient, 1});
                    // if (max_count < 2)
                    //     max_count = 2;
                }
            }

            for (auto& p : gradients) {
                temp = p.second + 1;
                if (temp > max_count) {
                    cout << temp << endl;
                    max_count = temp;
                }
            }

            if (result < max_count) {
                result = max_count;
            } else if (result < y_zero+1) {
                result = y_zero+1;
            }
        }
        return result;
    }
};