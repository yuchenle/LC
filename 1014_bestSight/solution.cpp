#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int length = values.size();
        if (length==2)
            return values[0]+values[1]-1;

        pair<int,int> dp[length]; // <cur_ret, idx_of_max_until>;

        dp[0]={0,0};
        if (values[0]>values[1])
            dp[1]={values[0]+values[1]-1,0};
        else
            dp[1]={values[0]+values[1]-1,1};
        int ret = dp[1].first;
        for (int i = 2; i < length; ++i) {
            int myval = values[i];
            int cur_ret = dp[i-1].first;
            int idx_max = dp[i-1].second;
            int val = values[idx_max]+values[i]+idx_max-i;
            int new_idx_max = idx_max;
            if ((values[i]+i)>=(values[idx_max]+idx_max)) {
                new_idx_max = i;
                // printf("changing new_idx_max to %d\n", new_idx_max);
            }

            if (val > cur_ret) {
                ret = val;
                dp[i] = {val, new_idx_max};
            } else {
                dp[i] = {cur_ret, new_idx_max};
            }
        }
        return dp[length-1].first;
    }
};

int main() {

    Solution s = Solution();
    vector<int> input = {8,1,5,2,6};
    vector<int> input2 = {4,7,5,8};
    vector<int> input3 = {7,8,8,10};
    vector<int> input4 = {7,2,6,6,9,4,3};
    cout << s.maxScoreSightseeingPair(input3) << endl;
    return 0;
}