#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
//     int countMaxOrSubsets(vector<int>& nums) {
//         int length = nums.size();
//         if(length==1)
//             return 1;

//         int maxOr = 0;
//         for (int i = 1; i < length; ++i) {
//             int orVal = nums[i-1] | nums[i];
//             if (orVal > maxOr)
//                 maxOr = orVal;
//         }

//         for (int i = 0; i < length; ++i) {

//         }
// };

    int countMaxOrSubsets(std::vector<int>& nums) {
        int max_or = 0;
        int n = nums.size();
        for (int num : nums) {
            max_or |= num;
        }

        int count = 0;
        for (int mask = 1; mask < (1 << n); ++mask) {
            int curr_or = 0;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    curr_or |= nums[i];
                }
            }
            if (curr_or == max_or) {
                ++count;
            }
        }
        return count;
    }
};

int main() {
    vector<int> vec = {3,1};
    vector<int> vec2 = {2,2,2};
    vector<int> vec3 = {3,2,1,5};
    Solution s = Solution();
    cout << s.countMaxOrSubsets(vec) << endl;
    cout << s.countMaxOrSubsets(vec2) << endl;
    cout << s.countMaxOrSubsets(vec3) << endl;
    return 0;
}