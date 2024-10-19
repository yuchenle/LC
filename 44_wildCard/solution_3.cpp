

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        dp[0][0] = true;

        for (int j = 1; j <= n; ++j) {
            if (p[j - 1] == '*')
                dp[0][j] = dp[0][j - 1];
        }

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                } else if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }

        return dp[m][n];
    }
};


int main() {
    Solution s = Solution();

    string s1 = "cb";
    string p1 = ",";
    string p2 = "?a";
    string p3 = "?b";

    string s4 = "cbb";
    string p4 = "c*b*b";

    string s5 = "aa";
    string p5 = "a";

    string s6 = "adceb";
    string p6 = "*a*b";

    string s7 = "aab";
    string p7 = "c*a*b";
    
    // cout<<s.isMatch(s1,p1)<<endl;
    // cout<<s.isMatch(s1,p2)<<endl;
    // cout<<s.isMatch(s1,p3)<<endl;
    // cout<<s.isMatch(s4,p4)<<endl;
    // cout<<s.isMatch(s5,p5)<<endl;
    cout<<s.isMatch(s6,p6)<<endl;
    cout<<s.isMatch(s7,p7)<<endl;

    return 0;
    
}
