#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // int maxLength = 0;
        // int length = s.size();
        // if (length <= 1)
        //     return length;

        // for (int i = 0; i < length; ++i){
        //     map<char, int> counter;
        //     int maxNonRepeat=0;
        //     if (maxLength >= length - i)
        //             break;
        //     for (int j = i; j < length; ++j) {
        //         counter[s[j]]++;
        //         if(counter[s[j]]>1)
        //             break;
        //         maxNonRepeat++;
        //         if(maxNonRepeat>maxLength)
        //             maxLength=maxNonRepeat;
        //     }
        // }
        // return maxLength;
        unordered_map<char, int> charMap;
        int maxLength = 0;
        int left = 0;

        for (int right = 0; right < s.size(); ++right) {
            char currentChar = s[right];

            if (charMap.find(currentChar) != charMap.end() && charMap[currentChar] >= left) {
                left = charMap[currentChar] + 1;
            }

            charMap[currentChar] = right;
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
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