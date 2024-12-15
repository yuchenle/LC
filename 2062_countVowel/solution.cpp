#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:

    bool isVowel(char ch) {
        if (ch=='a' ||
            ch=='e' ||
            ch=='i' ||
            ch=='o' ||
            ch=='u')
            return true;
        return false;
    }

    bool isVS(string subs) {
        bool ret = true;
        unordered_map<char, int> mm;
        if (subs.length() < 5)
            return false;
        for (char c : subs) {
            if (!isVowel(c))
                return false;
            mm[c]++;
        }
        ret &= (mm['a']>=1);
        ret &= (mm['e']>=1);
        ret &= (mm['i']>=1);
        ret &= (mm['o']>=1);
        ret &= (mm['u']>=1);
        return ret;
    }

    int countVowelSubstrings(string word) {
        int length = word.length();
        // printf("length is %d\n", length);
        if (length < 5)
            return 0;

        int **DP;
        DP = (int **)malloc(sizeof(int *) * length);
        for (int i = 0; i < length; ++i) {
            DP[i] = (int *) calloc(length, sizeof(int));
        }

        int ret = 0;
        for (int i = 0; i < length; ++i) {
            for (int j = 0; j < length; ++j) {
                if ((j - i + 1) < 5)
                    continue;
                if (DP[i][j-1]==1) {
                    DP[i][j] = isVowel(word[j]);
                    // printf("DP[%d][%d] = %d\n", i, j, DP[i][j]);
                    ret += DP[i][j];
                } else {
                    string subs = word.substr(i,j-i+1);
                    // printf("subs = %s\n", subs.c_str());
                    DP[i][j] = isVS(subs);
                    // printf("DP[%d][%d] = %d\n", i, j, DP[i][j]);
                    ret += DP[i][j];
                }
            }
        }
        return ret;
    }
};

int main() {
    Solution s = Solution();
    cout << s.countVowelSubstrings("cuaieuouac") << endl;

}