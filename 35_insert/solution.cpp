class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int length = nums.size();
        auto predicate = [target](int x) {
            return x >= target;
        };
        auto idx = std::find_if(nums.begin(),nums.end(),predicate);
        if (idx!=nums.end())
            return std::distance(nums.begin(), idx);
        else
            return length;
    }
};