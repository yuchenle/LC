#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1) {
            return strs[0];
        }

        bool done = false;
        string str0 = strs[0];
        int length = strs.size();
        int longestCP = 0;
        for (int i = 0; i < str0.size(); ++i) {
            if (!done) {
                for (int j = 1; j < length; j++) {
                    if (strs[j].size() == 0) {
                        return "";
                    }
                    if (strs[j][i]!=str0[i]) {
                        done = true;
                        printf("hahaha\n");
                        break;
                    }
                }
                longestCP++;
            } else {
                break;
            }
        }
        if (done)
            longestCP--;


        // printf("longestcp=%d\n", longestCP-1);
        return str0.substr(0, longestCP-1);
    }
};

int main() {
    Solution s=Solution();
    vector<string> strVec = {"flower","flow","flight"};
    vector<string> strVec2 = {"dog","racecar","car"};

    // cout << s.longestCommonPrefix(strVec) << endl;
    cout << s.longestCommonPrefix(strVec2) << endl;

    return 0;
}