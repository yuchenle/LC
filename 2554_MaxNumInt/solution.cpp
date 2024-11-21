class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int length = banned.size();
        unordered_set<int> mySet;
        for(int i = 0; i < length; ++i) {
            mySet.insert(banned[i]);
        }

        int curSum=0;
        int ret=0;
        for (int i = 1; i <= n; ++i) {
            if(mySet.find(i) == mySet.end() && (curSum+i) <= maxSum) {
                curSum += i;
                ret++;
            }
        }
        return ret;
    }
};
