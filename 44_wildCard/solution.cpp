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
    bool isMatch(string s, string p) {
        if (p.size()==0)
            return true;
        else
            if (s.size()==0)
                return false;

        int lengthS = s.size();
        int lengthP = p.size();

        int rightP = lengthP-1;

        int ret = true;
        int i;
        for (i = lengthS-1; i >= 0; --i) {
            if (rightP < 0)
                break;
            if (p[rightP] == '?' || s[i] == p[rightP]) {
                rightP--;
                continue;
            }
            if (p[rightP] == '*') {
                continue;
            }
            if (s[i] != p[rightP]) {
                ret = false;
                break;
            }
        }
        return ret && (i<0);
    }
};

int main() {
    Solution s = Solution();

    string s1 = "cb";
    string p1 = ",";
    string p2 = "?a";
    string p3 = "?b";

    string s4 = "caabaab";
    string p4 = "c*a*b";

    // cout<<s.isMatch(s1,p1)<<endl;
    // cout<<s.isMatch(s1,p2)<<endl;
    // cout<<s.isMatch(s1,p3)<<endl;
    cout<<s.isMatch(s4,p4)<<endl;   

    return 0;
    
}