#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int length=s.size();
        string ret(s);
        if (length==1)
            return s;
        int pos = length/2;
        if (length%2==1) {
            ret[pos] = s[pos];
        } else {
            char c = std::min(s[pos-1],s[pos]);
            ret[pos] = c;
            ret[pos-1] = c;
            pos-=2;
        }
        while(pos>=0) {
            char c = min(s[pos],s[length-1-pos]);
            ret[pos] = c;
            ret[length-1-pos] = c;
            pos--;
        }

        return ret;
    }
};

int main() {
    Solution s = Solution();
    cout << s.makeSmallestPalindrome("egcfe") << endl;
    return 0;
}