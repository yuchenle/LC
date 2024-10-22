#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        int s1[26] = {0};
        int s2[26] = {0};

        for (char c : s) {
            s1[c-'a']++;
        }
        for (char c : target) {
            s2[c-'a']++;
        }

        int ret = 0;
        bool done = false;
        while(1) {
            for (char c : target) {
                s1[c-'a']--;
                if (s1[c-'a']<0)
                    done=true;
            }
            if (done)
                break;
            else
                ret++;
        }
        return ret;
    }
};

int main() {
    Solution s = Solution();
    cout<<s.rearrangeCharacters("aabbcc", "bc")<<endl;
    return 0;
}