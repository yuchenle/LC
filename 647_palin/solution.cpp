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

    int countSubstrings(string s) {
        int ret = 0;
        int length = s.size();
        for (int i = 0; i < length; ++i) {
            for (int pal_length = 1; (i + pal_length) <= length; ++pal_length) {
                string subs = s.substr(i,pal_length);
                cout << "subs is " << subs << endl;
                if (isPal(subs))
                    ret++;
                else
                    break;
            }            
        }
        return ret;
    }
};

int main() {
    Solution s = Solution();
    cout << s.countSubstrings("abc") << endl;
    cout << s.countSubstrings("aaa") << endl;
    cout << s.countSubstrings("reer") << endl;
    return 0;
}