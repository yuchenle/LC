#include <vector>
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, vector<int>> mm;
        vector<int> res(nums1.size(), -1);
        for (int i = 0; i < nums2.size(); ++i) {
            mm[nums2[i]].push_back(i);
        }

        for (int i = 0; i < nums1.size(); ++i) {
            int starting_idx = mm[nums1[i]][0];
            for (int j = starting_idx; j < nums2.size(); ++j) {
                if (nums2[j] > nums1[i]) {
                    res[i] = nums2[j];
                    break;
                }
            }
        }

        return res;
    }
};