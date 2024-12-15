#include <vector>
#include <algorithm>
#include <iostream>
#include <utility>
#include <queue>

using namespace std;

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int length = classes.size();
        if (length == 1)
            return (classes[0][0]+extraStudents) / (classes[0][1]+extraStudents);

        vector<int> ratios(length, 0);
        for (int i = 0; i < length; ++i) {
            ratios[i] = classes[i][0]/classes[i][1];
        }

        priority_queue<pair<double, int>> increments;
        for (int i = 0; i < length; ++i) {
            double before = classes[i][0] / (double)classes[i][1];
            double after = (classes[i][0]+1)/(double)(classes[i][1]+1);
            // printf("classes[%d][0]+1 = %d , classes[%d][1]+1 = %d, ratio = %f\n", i, classes[i][0]+1, i, classes[i][1]+1, after-before);
            increments.push({after - before, i});
            // printf("incremenet[%d] = {%f, %d}\n", i, increments[i].first, increments[i].second);
        }

        while(extraStudents != 0) {
            extraStudents--;
            auto pp = increments.top();
            increments.pop();
            int idx_to_modify = pp.second;
            classes[idx_to_modify][0]++;
            classes[idx_to_modify][1]++;
            double before = classes[idx_to_modify][0] / (double)classes[idx_to_modify][1];
            double after = (classes[idx_to_modify][0]+1)/(double)(classes[idx_to_modify][1]+1);
            increments.push({after-before, idx_to_modify});
            // printf("idx_to_modify = %d, before = %f, after = %f\n", idx_to_modify, before, after);
            // printf("increments[0] = {%f, %d}\n", increments[0].first, increments[0].second);
        }

        double sumRatio = 0;
        for (int i = 0; i < length; ++i) {
            sumRatio += (classes[i][0]/(double)classes[i][1]);
        }

        return sumRatio/length;        
    }
};

int main() {
    Solution s = Solution();
    vector<vector<int>> input = {{1,2},{3,5},{2,2}};
    cout << s.maxAverageRatio(input, 2) << endl;
    return 0;
}