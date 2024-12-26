#include <vector>
#include <iostream>
#include <map>
#include <assert.h>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        int length = nums.size();
        assert(length>=1);
        unordered_map<int,int> DP[length];
        int ret = 0;

        if (length==1) {
            if (nums[0]==target)
                ret += 1;
            else if ((nums[0] * -1) == target)
                ret += 1;
            return ret;
        }
    
        DP[0][nums[0]]++;

        DP[0][-nums[0]]++;
        
        for (int i = 1; i < length; ++i) {
            for (auto elem : DP[i-1]) {
                int posSum = elem.first + nums[i];
                int negSum = elem.first - nums[i];
                // printf("possum = %d, negsum = %d\n",posSum, negSum);
                // if (posSum == target)
                //     ret += elem.second;
                // if (negSum == target)
                //     ret += elem.second;
                DP[i][posSum]+=elem.second;
                DP[i][negSum]+=elem.second;
            }
        }

        return DP[length-1][target];
    }
};

int main() {
    Solution s = Solution();
    vector<int> input = {1,1,1,1,1};
    vector<int> input2 = {1};
    vector<int> input3 = {22,25,21,8,32,36,26,22,12,26,32,1,11,21,19,50,2,1,19,32};
    vector<int> input4 = {0,0,0,0,0,0,0,0,1};
    int num = s.findTargetSumWays(input, 3);
    int num2 = s.findTargetSumWays(input2, 1);
    int num3 = s.findTargetSumWays(input3, 24);
    int num4 = s.findTargetSumWays(input4,1);
    // printf("num4 = %d\n", num4);
    printf("num = %d, %d, %d %d\n", num, num2, num3, num4);
    return 0;    
}