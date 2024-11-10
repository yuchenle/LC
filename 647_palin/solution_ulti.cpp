#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:

    bool isPal(string s) {
        int length = s.size();
        if (length==1)
            return true;

        bool ret = true;
        for (int i = 0; i < length/2; ++i) {
            if (s[i] != s[length-1-i]) {
                ret = false;
                break;
            }
        }
        return ret;
    }

    void printDP(int length, int **DP) {
        for (int i = 0; i < length; ++i) {
            for (int j = 0; j < length; ++j) {
                printf("%d ", DP[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }

    int countSubstrings(string s) {
        int ret = s.size();
        int length = s.size();
        int i = 0;

        // DP[i][j] = 1 if s[i..j] is a palindrome
        int **DP;
        DP = (int **)malloc(sizeof(int *) * length);
        for (int i = 0; i < length; ++i) {
            DP[i] = (int *)calloc(length, sizeof(int));
        }

        for (int i = 0; i < length; ++i) {
            // single characeter is a palindrome
            DP[i][i]=1;

            // two-character string is a palindrome if char1=char2
            if (i+1<length) {
                DP[i][i+1] = (s[i]==s[i+1]);
                ret+=DP[i][i+1];
            }
        }

        for (int i = length-1; i >= 0; --i) {
            for (int j = length-1; j >= 0; --j) {
                if (i>j) {
                    // DP[i][j] = 0;
                } else if (i==j) {
                    continue;
                } else if ((DP[i][j]==0) && ((j>0) && (i<length-1))) {
                    DP[i][j] = (s[j]==s[i]) && (DP[i+1][j-1]);
                    ret+=DP[i][j];
                }
            }
        }

        printDP(length, DP);
        return ret;
    }
};

int main() {
    Solution s = Solution();
    // cout << s.countSubstrings("abc") << endl;
    // cout << s.countSubstrings("aaa") << endl;
    cout << s.countSubstrings("aaaaa") << endl;
    // cout << s.countSubstrings("reer") << endl;
    return 0;
}