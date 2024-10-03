#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int res = 0;
        for (int i=s.length()-1; i >= 0; i--) {
            if (s[i] == ' ')
                if (res == 0)
                    continue;
                else
                    return res;
            else
                res++;
        }
        return res;
    }
};

int main() {
    Solution s = Solution();
    string str = "Hello World";
    string str2 = "   fly me   to   the moon  ";
    cout << s.lengthOfLastWord(str) << endl;
    cout << s.lengthOfLastWord(str2) << endl;
}