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
        int ret = s.size();
        int length = s.size();
        for (int i = 0; i < length; ++i) {
            int start_pos = i+1;
            int pos;
            while ((pos = s.find(s[i],start_pos)) != std::string::npos) {
                printf("pos = %d and start_pos = %d\n", pos, start_pos);
                int subs_length = pos - i + 1;
                string subs = s.substr(i, subs_length);
                cout << "subs is " << subs << endl;
                if (isPal(subs))
                    ret++;
                start_pos = pos+1;
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