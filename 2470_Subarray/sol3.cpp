#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    int subarrayLCM(vector<int>& nums, int k) {
        int length = nums.size();

        int ret = 0;
        for (int i = 0; i < length; ++i) {
            if (nums[i] == k)
                ret++;
            if (k%nums[i] != 0)
                continue;
            int curr_lcm = nums[i];
            for (int j = i+1; j < length && k%nums[j]==0; ++j) {
                curr_lcm = lcmOfTwoNumbers(curr_lcm, nums[j]);
                if (curr_lcm>k)
                    break;
                if (curr_lcm == k)
                    ret++;
            }
        }
        return ret;
    }

private:
    int gcdOfTwoNumbers(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    int lcmOfTwoNumbers(int a, int b) {
        return (a / gcdOfTwoNumbers(a, b)) * b;
    }
};

int main() {
    Solution s = Solution();
    vector<int> ex1 = {3,6,2,7,1};
    cout<<s.subarrayLCM(ex1, 6)<<endl;
    return 0;
}