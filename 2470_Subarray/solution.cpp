#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    int determineSub(vector<int>& helperArray, int k) {
        printf("determineSub with %d elements\n", helperArray.size());
        int length = helperArray.size();
        int ret = 0;
        for (int i = 1; i < (1<<length);++i) {
            int LCM = 1;
            for (int j = 0; j < helperArray.size(); ++j) {
                if (i & (1<<j))
                    LCM *= helperArray[j];
            }
            if (LCM == k)
                ret++;
        }
        return ret;
    }

    int subarrayLCM(vector<int>& nums, int k) {
        int length = nums.size();
        
        int maxSub=0;
        if (length==1)
            return (int)nums[0]==k;
        // DP[i] = number of subarrays of num[:i] having LCM as k;
        pair<int,vector<int>> DP[length];
        // DP[i+1] = ?DP[i];
        for (int i = 0; i < length; ++i) {
            if (i==0) {
                DP[i] = {(int)(nums[i]==k), {nums[i]}};
            } else {
                if (k % nums[i] != 0 ) {
                    DP[i] = {0,{}};
                } else if (DP[i-1].first==0) {
                    if (k == nums[i])
                        DP[i] = {1,{nums[i]}};
                    else
                        DP[i] = {0,{nums[i]}};
                } else {
                    //generic case
                    vector<int> helperArray = DP[i-1].second;
                    helperArray.push_back(nums[i]);
                    DP[i].first = determineSub(helperArray, k);
                    DP[i].second = helperArray;
                }
            }
            if (DP[i].first > maxSub)
                    maxSub = DP[i].first;
        }
        for (int i =0;i<length;++i)
            printf("DP[%d] = %d\n", i,DP[i].first);
        return maxSub;
    }
};

int main() {

    Solution s = Solution();

    vector<int> ex1 = {3,6,2,7,1}; // DP[{0,1},{1,]
    vector<int> ex2 = {3,6,6,7,1};
    vector<int> ex3 = {2,1,5,5};
    vector<int> ex4 = {5,1,1,1,2}; // DP={0,1,3,4+3}

    // {3, 6}
    // { , 6}
    // { ,  , 6};
    // { , 6, 6};
    // {3, 6, 6}

    // {3, 6}
    // { , 6}
    // { , 6, 2}
    // {3, 6, 2}
    int k1 = 6;
    int k3 = 1;
    int k4 = 1;
    // cout<<s.subarrayLCM(ex1,6)<<endl;
    // cout<<s.subarrayLCM(ex2,6)<<endl;
    cout<<s.subarrayLCM(ex4,k4)<<endl;
    return 0;
}