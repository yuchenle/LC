#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        int length = nums.size();

        // basic case where there is only one element
        if (length==1)
            return 1;
        
        int prev = nums[0];
        // pair.first is the occurrences of the number (key)
        // pair.second is the actual DP, the number of integers that are smaller than Key
        unordered_map<int, pair<int, int>> DP;
        for (int i = 0; i < length; ++i) {
            DP[nums[i]].first++;
            if (nums[i]>prev) {
                DP[nums[i]].second = DP[prev].first+DP[prev].second;
                prev = nums[i];
            }
        }

        for (auto elem : DP) {
            printf("key = %d, pair.first = %d, pair.second = %d\n", elem.first, elem.second.first, elem.second.second);
        }

        return 0;
    }
};

int main() {
    Solution s = Solution();
    vector<int> input = {2,3,4,4,4};
    s.minLengthAfterRemovals(input);
    return 0;
}