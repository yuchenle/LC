#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> counter;
        int length = s.size();
        if (length <= 1) {
            return length;
        }

        int ret = 1;
        while (1) {
            bool found;
            for (int j = 0; j < length; ++j) {
                string substr = s.substr(j,ret);
                counter = map<char,int>();
                found = false;
                for (int idxC = 0; idxC < substr.size(); ++idxC) {
                    counter[substr[idxC]]++;
                    if (counter[substr[idxC]]>1) {
                        break;
                    }
                    if (idxC == ret - 1) {
                        found = true;
                        ret++;
                        break;
                    }
                }
                if (found)
                    break;
            }
            if (found == false)
                return ret - 1;
            if (ret > length) {
                if (found)
                    return ret-1;
                else
                    return ret-2;
            }
        }
        return ret;
    }
};

int main() {
    Solution s = Solution();
    cout<<s.lengthOfLongestSubstring("abcabcbb")<<endl;
    cout<<s.lengthOfLongestSubstring("bbbbb")<<endl;
    cout<<s.lengthOfLongestSubstring("pwwkew")<<endl;
    cout<<s.lengthOfLongestSubstring("aab")<<endl;
    cout<<s.lengthOfLongestSubstring("bwf")<<endl;


    return 0;
}