#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int length = nums.size();
        if (length == 2)
            return 1;
        // std::get<0>(DP[i]) = previousIncreasingArray.size()
        // std::get<1>(DP[i]) = currentIncreasingArray.size()
        // std::get<2>(DP[i]) = ret for array from 0 to i
        // end result is std::get<2>(DP[length-1])
        std::tuple<int, int, int> DP[length];
        DP[0] = {0,1,0};
        // for (int i = 1; i < length; ++i) {
        //     std::get<0>(DP[i]) = {};
        //     std::get<1>(DP[i]) = {nums[i-1]};
        //     std::get<2>(DP[i]) = 0;
        // }

        for (int i = 1; i < length; ++i) {
            if (std::get<0>(DP[i-1]))
                std::get<0>(DP[i]) = std::get<0>(DP[i-1]);
            if (nums[i]>nums[i-1]) {
                std::get<1>(DP[i]) = std::get<1>(DP[i-1])+1;
            } else {
                std::get<0>(DP[i]) = std::get<1>(DP[i-1]);
                // printf("index %d, setting lastArray to size of %d\n", i, std::get<0>(DP[i]));
                std::get<1>(DP[i]) = 1;
            }
            // printf("size of building array is %d\n", std::get<1>(DP[i]));
            int m = std::max(std::get<1>(DP[i])/2,
                             std::min(std::get<1>(DP[i]),
                                      std::get<0>(DP[i])));

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
    // vector<int> input = {2,5,7,8,9,2,3,4,3,1};
    // vector<int> input2 = {1,2,3,4,4,4,4,5,6,7};
    vector<int> input = {5,8,-2,-1};
    cout << s.maxIncreasingSubarrays(input) << endl;
}