#include <vector>
#include <string>

using namespace std;

class Solution {
public:

    static inline bool isVowel(char c) {
        if (c=='a' ||
            c=='e' ||
            c=='u' ||
            c=='i' ||
            c=='o')
            return true;
        return false;
    }

    static inline bool isOkay(string s) {
        int s_length = s.size();
        if (isVowel(s[0]) && isVowel(s[s_length-1]))
            return true;
        return false;
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int words_length = words.size();
        int yesOrNo[words_length];
        for (int i = 0; i < words_length; ++i) yesOrNo[i] = isOkay(words[i]);

        vector<int> ret;
        for (int i = 0; i < queries.size(); ++i) {
            int start = queries[i][0];
            int end = queries[i][1];
            int cur_sum = 0;
            for (int j = start; j <= end; ++j) {
                cur_sum += yesOrNo[j];
            }
            ret.push_back(cur_sum);
        }
        return ret;
    }
};