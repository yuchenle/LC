#include <iostream>
#include <vector>
#include <map>

using namespace std;
class Solution {
    map<int,int> intmap;
    int numElem = 0;
public:
    Solution() : intmap(map<int,int>()) {}

    ~Solution() {}

    vector<int> singleNumber(vector<int>& nums) {
        int length = nums.size();
        if (length == 2) {
            return nums;
        }

        for (int i = 0; i < length; ++i) {
            intmap[nums[i]]++;
        }

        vector<int> ret;
        for (auto MapP : intmap) {
            if (MapP.second==1) {
                ret.push_back(MapP.first);
                if (ret.size()==2)
                    return ret;
            }
        }
        return ret;
    }
};

int main() {
    Solution s = Solution();
    s.singleNumber({});
    return 0;
}