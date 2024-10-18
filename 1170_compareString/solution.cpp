#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int freq(string s) {
        int fq[26] = {0};
        int smallestChar = 27;
        for (auto c : s) {
            int cha = (int)c-'a';
            if (cha < smallestChar)
                smallestChar = cha;
            fq[cha]++;
        }
        return fq[smallestChar];
    }

    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> ret;
        vector<int> freq_words;
        int lengthQuery = queries.size();
        int lengthWords = words.size();

        for (int i = 0; i < lengthWords; ++i) {
            freq_words.push_back(freq(words[i]));
        }

        for (int i = 0; i < lengthQuery; ++i) {
            int f = freq(queries[i]);
            int counter = 0;
            for (int j = 0; j < lengthWords; ++j) {
                if (f < freq_words[j])
                    counter++;
            }
            ret.push_back(counter);
        }
        return ret;
    }
};

int main() {

    vector<string> q1 = {"bbb","cc"};
    vector<string> w1 = {"a","aa","aaa","aaaa","bbbbba"};
    vector<string> q2 = {"cbd"};
    vector<string> w2 = {"zaaaz"};
    Solution s = Solution();
    // for (auto ss : w1) {
    //     printf("frequency of %s is %d\n", ss.c_str(), s.freq(ss));
    // }
    vector<int> res1 = s.numSmallerByFrequency(q1,w1);
    for (int j = 0; j < res1.size(); ++j) {
        printf("%d ", res1[j]);
        if (j==res1.size()-1)
            printf("\n");
    }
    
    return 0;
}