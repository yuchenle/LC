// Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

// '?' Matches any single character.
// '*' Matches any sequence of characters (including the empty sequence).
// The matching should cover the entire input string (not partial).

// Example 1:

// Input: s = "aa", p = "a"
// Output: false
// Explanation: "a" does not match the entire string "aa".
// Example 2:

// Input: s = "aa", p = "*"
// Output: true
// Explanation: '*' matches any sequence.
// Example 3:

// Input: s = "cb", p = "?a"
// Output: false
// Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool allStar(string ss) {
        bool ret = true;
        for (char c : ss)
            ret &= (c=='*');
        return ret;
    }
    bool isMatch(string s, string p) {
        int lengthP = p.size();
        int lengthS = s.size();
        if(lengthP == 0)
            return true;

        if(lengthS == 0) {
            if(lengthP==1 && allStar(p)) {
                return true;
            } else {
                return false;
            }
        }

        if (lengthP==1 && p[0]=='*')
            return true;

        int rightP = lengthP-1;
        int rightS = lengthS-1;
        bool ret = true;
        while(rightP >= 0 && rightS>=0) {
            if (p[rightP] == s[rightS] || p[rightP] == '?') {
                rightP--;
                rightS--;
            } else if  (p[rightP] != '*') {
                if (p[rightP] != s[rightS]) {
                    ret = false;
                    break;
                }
            } else {
                // p[rightP] == '*'
                bool consume = isMatch(s.substr(0,max(0,rightS)), p.substr(0,max(0,rightP)));
                printf("comparing s=%s and p=%s, result = %d\n", s.substr(0,rightS).c_str(), p.substr(0,rightP).c_str(), (int) consume);

                bool notConsume = isMatch(s.substr(0,max(0,rightS)), p.substr(0,rightP+1));
                printf("comparing s=%s and p=%s, result = %d\n", s.substr(0,rightS).c_str(), p.substr(0,rightP+1).c_str(), (int) notConsume);

                bool notConsumeS = isMatch(s.substr(0,rightS+1), p.substr(0,max(0,rightP)));
                printf("comparing s=%s and p=%s, result = %d\n", s.substr(0,rightS+1).c_str(), p.substr(0,rightP).c_str(), (int) notConsumeS);

                rightS=-1;
                rightP=-1;
                ret = (consume|notConsume|notConsumeS);
                break;
            }
        }
        return ret && rightS<0 && allStar(p.substr(0,max(0,rightP)));
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