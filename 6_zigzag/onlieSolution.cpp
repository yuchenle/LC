#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        int N = s.size(), d = (numRows - 1) * 2;
        string ans;
        for (int i = 0; i < numRows; ++i) {
            int w = 2 * i;
            for (int j = i; j < N;) {
                ans += s[j];
                w = d - w;
                if (!w) w = d;
                j += w;
            }
        }
        return ans;
    }
};

int main() {
    Solution *s = new Solution();
    // s->convert("Synopsys", 4);
    // printf("%s\n", s->convert("A", 1).c_str());
    // printf("%s\n", s->convert("Synopsis", 4).c_str());
    printf("%s\n", s->convert("Apalindromeisaword,phrase,number,orothersequenceofunitsthatcanbereadthesamewayineitherdirection,withgeneralallowancesforadjustmentstopunctuationandworddividers.", 3).c_str());
    // s->printMat();
    delete s;
    return 0;
}