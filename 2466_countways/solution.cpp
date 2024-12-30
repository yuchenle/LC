#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        int modulo = 1000000007;
        int DP[high+1];
        for (int i = 0; i <= high; ++i) DP[i] = 0;
        if (zero==1)
            DP[1]++;
        if (one == 1)
            DP[1]++;

        for (int i = 2; i <= high; ++i) {
            if ((i-zero)>=0)
                DP[i]+=DP[i-zero];
            if ((i-one)>=0)
                DP[i]+=DP[i-one];
            if (i%zero==0 && DP[i-zero]==0)
                DP[i]++;
            if (i%one==0 && DP[i-one]==0)
                DP[i]++;
            DP[i] %= modulo;
        }


        int ret = 0;
        for (int i = low; i <= high; ++i) {
            ret+=DP[i];
            ret %= modulo;
        }
        return ret;
    }
};

int main() {
    Solution s = Solution();
    cout<<s.countGoodStrings(3,3,1,1)<<endl;
    cout<<s.countGoodStrings(2,3,1,2)<<endl;
    // cout<<s.countGoodStrings(5,5,5,2)<<endl;
    cout<<s.countGoodStrings(200,200,10,1)<<endl;
    return 0;
}