#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int length = nums.size();
        if (length == 1)
            return nums[0];
        if (length == 2)
            return min(nums[0],nums[1]);

        std::sort(nums.begin(), nums.end());

        int ret = 0;
        for (int i = 0; i < length; ++i) {
            if (i%2==0)
                ret += nums[i];
        }
        return ret;
    }
};