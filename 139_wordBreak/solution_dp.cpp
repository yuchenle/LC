#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool wordBreak(std::string s, std::vector<std::string>& wordDict) {

        std::unordered_set<std::string> wordSet(wordDict.begin(), wordDict.end());

        int n = s.size();

        std::vector<bool> dp(n + 1, false);
        dp[0] = true;


        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {

                if (dp[j] && wordSet.find(s.substr(j, i - j)) != wordSet.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};