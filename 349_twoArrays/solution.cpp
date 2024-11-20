
#include <unordered_set>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        unordered_set<int> mm;
        unordered_set<int> another;
        int length1 = nums1.size();
        int length2 = nums2.size();

        for (int i = 0; i < length1;++i) {
            mm.insert(nums1[i]);
        }

        for (int i = 0; i < length2; ++i) {
            if(mm.find(nums2[i]) != mm.end()) {
                another.insert(nums2[i]);
            }
        }

        for(auto ii : another) {
            ret.push_back(ii);
        }
        return ret;
    }
};

int main()
{
    std::cout<<"Hello World";

    return 0;
}
