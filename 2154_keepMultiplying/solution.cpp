class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int length = nums.size();
        unordered_set<int> ha;
        for (int i = 0; i < length; ++i) {
            ha.insert(nums[i]);
        }

        bool cc=true;
        while(cc) {
            cc = false;
            if (ha.find(original)!=ha.end()) {
                cc = true;
                original*=2;
            }
        }
        return original;
    }
};