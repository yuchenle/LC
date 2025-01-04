#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;


class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<pair<int,int>> tmp(26);
        int length = s.size();
        set<string> ss;
        for (int i = 0; i < 26; ++i) {
            tmp[i].first = length;
            tmp[i].second = -1;
        }

        for (int i = 0; i < length; ++i) {
            if (i < tmp[s[i]-'a'].first)
                tmp[s[i]-'a'].first = i;
            else if (i > tmp[s[i]-'a'].second)
                tmp[s[i]-'a'].second = i;
        }

        for (int i = 0; i < 26; ++i) {
            unordered_map<char, int> tmp_count;
            for (int j = tmp[i].first+1; j < tmp[i].second; ++j) {
                if (tmp_count[s[j]])
                    continue;
                else
                    tmp_count[s[j]]++;
                string tmp_s = "";
                tmp_s += s[tmp[i].first];
                tmp_s += s[j];
                tmp_s += s[tmp[i].second];
                ss.insert(tmp_s);
            }
        }

        // for (auto mystr : ss) {
        //     printf("%s\n", mystr.c_str());
        // }

        return ss.size();
    }
};

int main() {
    Solution s = Solution();
    string input = "aabca";
    string input2 = "bbcbaba";
    string input3 = "aaabbbcccdddeeefffggghhhiiijjjkkklllmmmnnnooopppqqqrrrssstttuuuvvvwwwxxxyyyzzzaaabbbcccdddeeefffggghhhiiijjjkkklllmmmnnnooopppqqqrrrssstttuuuvvvwwwxxxyyyzzz";
    cout<<s.countPalindromicSubsequence(input3)<<endl;
    return 0;
}