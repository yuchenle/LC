#include <vector>

using namespace std;

class Solution {
public:

    void swap(vector<int>& nums, int idx1, int idx2) {
        int tmp = nums[idx1];
        nums[idx1] = nums[idx2];
        nums[idx2] = tmp;
        printArray(nums);
    }

    void printArray(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i)
            printf("%d ", nums[i]);

        printf("\n");
    }

    vector<int> sortArrayByParityII(vector<int>& nums) {
        int length = nums.size();
        for (int i = 0; i < length; ++i) {
            if (i%2==0 && nums[i]%2!=0) {
                for (int j = i+1; j < length; ++j) {
                    if (nums[j]%2==0) {
                        swap(nums, i, j);
                        break;
                    }
                }
            } else if (i%2==1 && nums[i]%2!=1) {
                for (int j = i+1; j < length; ++j) {
                    if (nums[j]%2==1) {
                        swap(nums, i, j);
                        break;
                    }
                }
            }
        }
        printArray(nums);
        return nums;
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