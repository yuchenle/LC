#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int length = nums.size();
        if (length == 2)
            return 1;
        // std::get<0>(DP[i]) = previousIncreasingArray
        // std::get<1>(DP[i]) = currentIncreasingArray
        // std::get<2>(DP[i]) = ret for array from 0 to i
        // end result is std::get<2>(DP[length-1])
        std::tuple<vector<int>, vector<int>, int> DP[length];
        DP[0] = {{},{nums[0]},0};
        // for (int i = 1; i < length; ++i) {
        //     std::get<0>(DP[i]) = {};
        //     std::get<1>(DP[i]) = {nums[i-1]};
        //     std::get<2>(DP[i]) = 0;
        // }

        for (int i = 1; i < length; ++i) {
            if (std::get<0>(DP[i-1]).size())
                std::get<0>(DP[i]) = std::get<0>(DP[i-1]);
            if (nums[i]>nums[i-1]) {
                std::get<1>(DP[i]) = std::get<1>(DP[i-1]);
                std::get<1>(DP[i]).push_back(nums[i]);
            } else {
                std::get<0>(DP[i]) = std::get<1>(DP[i-1]);
                // printf("index %d, setting lastArray to size of %zu\n", i, std::get<0>(DP[i]).size());
                std::get<1>(DP[i]) = {nums[i]};
            }
            // printf("size of building array is %zu\n", std::get<1>(DP[i]).size());
            // for (auto aa : std::get<1>(DP[i])) {
            //     printf("%d ",aa);
            // }
            // printf("\n");
            int m = std::max(std::get<1>(DP[i]).size()/2,
                             std::min(std::get<1>(DP[i]).size(),
                                      std::get<0>(DP[i]).size()));

            if (m > std::get<2>(DP[i-1])) {
                std::get<2>(DP[i]) = m;
            } else {
                std::get<2>(DP[i]) = std::get<2>(DP[i-1]);
            }
            // printf("index %d, m = %d, DP[%d][%d] = %d and\n", i, m, i, 2, std::get<2>(DP[i]));
        }
        // printf("result is: \n");
        return std::get<2>(DP[length-1]);
    }
};

int main() {
    Solution s = Solution();
    vector<int> input = {2,5,7,8,9,2,3,4,3,1};
    vector<int> input2 = {1,2,3,4,4,4,4,5,6,7};
    cout << s.maxIncreasingSubarrays(input2) << endl;
}