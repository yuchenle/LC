#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int length1 = nums1.size();
        int length2 = nums2.size();
        vector<int> helper1;
        int ret = 0;
        if (length2%2==1)
            for (int i = 0; i < length1; ++i) {
                ret^=nums1[i];
            }

        if (length1%2==1)
            for (int j = 0; j < length2; ++j) {
                ret ^= nums2[j];
            }

        return ret;
    }
};

int main() {
    Solution s = Solution();
    vector<int> in1 = {10,2,5,0};
    vector<int> in2 = {2,1,3};
    cout << s.xorAllNums(in1, in2) << endl;
    return 0;
}