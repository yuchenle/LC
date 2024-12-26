#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int length = nums.size();
        int ret = 0;
        int mask = (1<<length)-1;
        for (int i = 0; i <= mask; ++i) {
            int sum = 0;
            for (int j = 0; j < length; ++j) {
                if (1&(i>>j))
                    sum += nums[j];
                else
                    sum -= nums[j];
            }
            if (sum == target)
                ret++;
        }
        return ret;
    }
};

int main() {
    Solution s = Solution();
    vector<int> input = {1,1,1,1,1};
    vector<int> input2 = {1};
    vector<int> input3 = {22,25,21,8,32,36,26,22,12,26,32,1,11,21,19,50,2,1,19,32};
    int num = s.findTargetSumWays(input3, 24);
    printf("num = %d\n", num);
    return 0;    
}