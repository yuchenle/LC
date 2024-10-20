#include <vector>

using namespace std;

class Solution {
public:

    vector<int> sortArrayByParityII(vector<int>& nums) {
        int length = nums.size();
        int idx_even[length/2];
        int idx_odd[length/2];
        vector<int> ret;
        int pos_even = 0;
        int pos_odd = 0;

        for (int i = 0; i < length; ++i) {
            if (nums[i]%2==0)
                idx_even[pos_even++] = i;
            else
                idx_odd[pos_odd++] = i;
        }
        pos_even = 0;
        pos_odd = 0;

        for (int i = 0; i < length; ++i) {
            if (i%2==0)
                ret.push_back(nums[idx_even[pos_even++]]);
            else
                ret.push_back(nums[idx_odd[pos_odd++]]);
        }

        return ret;
    }
};

int main() {
    Solution s = Solution();
    vector<int> nums1 = {4,2,5,7};
    vector<int> nums2 = {3,0,4,0,2,1,3,1,3,4};

    // s.sortArrayByParityII(nums1);
    s.sortArrayByParityII(nums2);
    return 0;
}