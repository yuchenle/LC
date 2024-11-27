class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int length = nums.size();
        auto pred = [target](int i) {
            return i == target;
        };
        int start, end;
        auto idx = std::find_if(nums.begin(), nums.end(), pred);
        if (idx == nums.end()) {
            printf("didn't find\n");
            start = -1;
            end = -1;
        } else {
            start = std::distance(nums.begin(), idx);
            printf("found, start = %d\n", start);
            int ss = start;
            for (; ss < length; ++ss) {
                if (nums[ss] > target) {
                    end = ss - 1;
                    break;
                }
            }
            if (ss == length)
                end = length-1;
        }
        return {start, end};
    }
};