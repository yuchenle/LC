#include <vector>
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    long long findScore(vector<int>& nums) {
        int length = nums.size();
        vector<int> marked(length, 0);
        if (length == 1)
            return nums[0];
        
        map<int,vector<int>> mm;
        for (int i = 0; i < length; ++i) {
            mm[nums[i]].push_back(i);
        }

        
        long long ret = 0;
        for (auto elem: mm) {
            for (auto idx : elem.second) {
                if (marked[idx]==0) {
                    ret += elem.first;
                    marked[idx] = 1;
                    marked[max(idx-1,0)] = 1;
                    marked[min(idx+1, length-1)] = 1;
                }
            }
        }

        return ret;
    }
};

int main() {
    Solution s = Solution();
    vector<int> input = {2,1,3,4,5,2};
    vector<int> input2 = {2,3,5,1,3,2};
    cout<<s.findScore(input2)<<endl;
    return 0;
}