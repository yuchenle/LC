#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int idx = haystack.find(needle);
        return idx == string::npos? -1 : idx;
    }
};

int main() {
    string s1 = "sadbutsad";
    string s2 = "sad";
    Solution sol = Solution();
    cout<<sol.strStr(s1,s2)<<endl;
    return 0;
}