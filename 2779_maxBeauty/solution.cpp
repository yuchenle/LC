#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    int maximumBeauty(std::vector<int>& nums, int k) {
        // Sort the array
        std::sort(nums.begin(), nums.end());
        
        // Initialize variables
        int max_beauty = 0;
        int left = 0;

        // Use sliding window
        for (int right = 0; right < nums.size(); ++right) {
            // Check if the current range exceeds `2 * k`
            while (nums[right] - nums[left] > 2 * k) {
                ++left;
            }

            // Update the maximum beauty
            max_beauty = std::max(max_beauty, right - left + 1);
        }

        return max_beauty;
    }
};

int main() {
    Solution s = Solution();
    vector<int> input = {5,57,46}; //15
    vector<int> input2 = {81,76,40}; //23
    cout << s.maximumBeauty(input2,5) << endl;
    return 0;
}