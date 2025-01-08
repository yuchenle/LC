#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    bool isPrefixAndSuffix(string sa, string sb) {
        int lengtha = sa.size();
        int lengthb = sb.size();

        if (lengthb < lengtha)
            return false;
        
        for (int i = 0; i < lengtha; ++i) {
            if (sa[i]!=sb[i])
                return false;
        }

        int pos = lengthb-1;
        for (int i = lengtha-1; i >= 0; --i) {
            if (sa[i]!=sb[pos--])
                return false;
        }

        return true;
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        int length = words.size();
        int ret=0;
        for (int i = 0; i < length; ++i) {
            for (int j = i+1; j < length; ++j) {
                if (isPrefixAndSuffix(words[i], words[j]))
                    ret++;
            }
        }

        return ret;
    }
};

int main() {
    Solution s = Solution();
    vector<string> input = {"a","aba","ababa","aa"};
    vector<string> input2 = {"pa","papa","ma","mama"};
    cout<<s.countPrefixSuffixPairs(input)<<endl;
    cout << s.countPrefixSuffixPairs(input2) << endl;
    return 0;
}
