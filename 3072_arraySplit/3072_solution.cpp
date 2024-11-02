#include <vector>
#include <iostream>


using namespace std;

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> left;
        vector<int> right;
        int length = nums.size();
        if (length < 3)
            return left;

        left.push_back(nums[0]);
        right.push_back(nums[1]);
        for (int i = 2; i < length; ++i) {
            int leftS = greaterCount(left, nums[i]);
            int rightS = greaterCount(right, nums[i]);
            if (leftS > rightS) {
                left.push_back(nums[i]);
            } else if (leftS < rightS) {
                right.push_back(nums[i]);
            } else if (leftS==rightS) {
                if (left.size() < right.size()) {
                    left.push_back(nums[i]);
                } else if (left.size() > right.size()) {
                    right.push_back(nums[i]);
                } else {
                    left.push_back(nums[i]);
                }
            }
        }

        left.insert(left.end(), right.begin(), right.end());
        return left;
    }

    int greaterCount(vector<int>& num, int val) {
        int length = num.size();
        int ret = 0;
        for (int i = 0; i < length; ++i) {
            if (num[i]>val)
                ret++;
        }
        return ret;
    }
};

int main() {
    Solution s=Solution();
    vector<int> input({37,79,71});
    vector<int> input2({13,53,82,67});
    // vector<int> res = s.resultArray(input);
    vector<int> res = s.resultArray(input);
    for (int i = 0; i < res.size(); ++i) {
        printf("%d ", res[i]);
    }
    printf("\n");
    return 0;
}