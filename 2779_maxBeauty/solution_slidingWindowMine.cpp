#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    int maximumBeauty(std::vector<int>& nums, int k) {
        int length = nums.size();
        
        if (length < 2)
            return 1;
        int max_beauty = 0;

        std::sort(nums.begin(), nums.end());
        
        int left = 0, right = 0;

        for (right=1;right<length;++right) {
            while(nums[right] - nums[left] > 2*k) {
                left++;
            }
            if ((right - left + 1) > max_beauty)
                max_beauty = right - left + 1;
        }

        return max(max_beauty,1);
    }
};

int main() {
    Solution s = Solution();
    vector<int> input = {5,57,46}; //15
    vector<int> input2 = {81,76,40}; //23
    cout << s.maximumBeauty(input,7) << endl;
    return 0;
}