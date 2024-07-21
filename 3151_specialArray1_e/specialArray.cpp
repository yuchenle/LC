#include <vector>
#include <stdio.h>

using namespace std;

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        bool res = true;
        int arraySize = nums.size();
        if (arraySize==1)
          return res;

        for (int i = 1; i < arraySize; ++i) {
            int prevParity = nums[i-1]%2;
            int currentParity = nums[i]%2;
            if (currentParity==prevParity)
                res = false;
        }
        return res;
    }
};

int main() {
    Solution S;
    vector<int> vec1 = {1,5};
    vector<int> vec2 = {2,1,4};
    vector<int> vec3 = {4,3,1,6};
    printf("S(1) = %d\n", S.isArraySpecial(vec1));
    printf("S(2) = %d\n", S.isArraySpecial(vec2));
    printf("S(3) = %d\n", S.isArraySpecial(vec3));
    return 0;
}