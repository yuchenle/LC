#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        int length = nums.size();

        if (length == 1)
            return nums[0];
        
        int num_neg = 0;
        long long result = 1;
        int max_neg = -10;
        int max_pos = 0;
        int non_zero = 0;

        for (int i = 0; i < length; ++i) {
            if (nums[i] != 0)
                non_zero++;
            if (nums[i] < 0) {
                num_neg++;
                if (nums[i] > max_neg)
                  max_neg = nums[i];
            }
            if (nums[i] != 0)
                result *= nums[i];

            if (nums[i] > max_pos)
                max_pos = nums[i];
        }

        if (non_zero == 0)
            return 0;

        if (num_neg %2 == 0)
            return result;

        if (non_zero == 1)
            return max(max_pos, 0);

        return result / max_neg;
    }
};

int main() {
    Solution s = Solution();
    vector<int> v1{3,-1,-5,2,5,-9};
    vector<int> v2{-4,-5,-4};
    vector<int> v3{-2,-3,8,9};
    vector<int> v4{0,-1};
    vector<int> v5{-9,-3,0,-7};

    // cout << s.maxStrength(v1) << endl;
    // cout << s.maxStrength(v2) << endl;
    // cout << s.maxStrength(v3) << endl;
    cout << s.maxStrength(v4) << endl;
    cout << s.maxStrength(v5) << endl;
    return 0;
}