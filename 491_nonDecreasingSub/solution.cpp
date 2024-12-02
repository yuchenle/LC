#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:

    bool isNonDecreasing(vector<int>& subV) {
        int length = subV.size();
        if (length < 2)
            return false;

        bool ret = true;
        for (int i = 1; i < length; ++i) {
            if (subV[i] < subV[i-1]) {
                ret = false;
                break;
            }
        }
        return ret;
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int length = nums.size();
        vector<vector<int>> ret;
        for (int i = 0; i < 1<<length; ++i) {
            vector<int> subV;
            for (int j = 0; j < length; ++j) {
                if (1 & i >> j)
                    subV.push_back(nums[j]);
            }
            // printf("length of subV is %zu, with i = %d\n", subV.size(), i);
            // for (auto elem : subV)
            //     printf("%d ", elem);
            // printf("\n");
            if (isNonDecreasing(subV) && std::find(ret.begin(), ret.end(), subV) == ret.end())
              ret.push_back(subV);
        }
        return ret;
    }
};

int main() {
    Solution s = Solution();
    vector<int> input = {4,6,7,7};
    auto arr = s.findSubsequences(input);
    printf("there are %zu results\n", arr.size());
    for (auto vec : arr) {
        for (auto elem : vec) {
            cout << elem << " " ;
        }
        cout << endl;
    }

    return 0;
}