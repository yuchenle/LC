#include <vector>
#include <string>
#include <map>
#include <iostream>

using namespace std;


class Solution {
public:
    string longestWord(vector<string>& words) {
        unordered_map<int, vector<string>> meh;
        /* vector of string of length i, and smallest in the array */
        pair<vector<string>,string> DP[31];
        int length = words.size();
        for (int i = 0; i < length; ++i) {
            int length_string = words[i].size();
            meh[length_string].push_back(words[i]);
        }

        if (meh[1].size()==0) {
            return "";
        }

        string minn = "z";
        vector<string> tmpVec;
        for (auto str: meh[1]) {
            tmpVec.push_back(str);
            if (str < minn) {
                minn=str;
            }
        }

        DP[0] = {{},"\0"};
        DP[1] = {tmpVec, minn};

        int res_length=2;

        bool continueOrNot = true;

        while(continueOrNot && res_length <= 30) {
            continueOrNot = false;
            bool found = false;
            string minn(res_length,'z');

            // printf("res_length = %d , minn = %s\n",res_length, minn.c_str());

            /* for each word of length res_length */
            for(auto subword: meh[res_length]) {

                /* for each beginning of res_length-1 in DP[i-1] */
                for (auto beginning: DP[res_length-1].first) {

                    /* check if DP[res_length-1] is in subword*/
                    if(subword.find(beginning) == 0) {
                        // printf("res_length = %d, found %s in %s\n", res_length, beginning.c_str(), subword.c_str());
                        continueOrNot = true;
                        DP[res_length].first.push_back(subword);
                        /* if yes and determine the smallest subword of res_length*/
                        if(subword <= minn) {
                            minn = subword;
                        }
                    }
                }
            }

            if(continueOrNot) {
                DP[res_length].second = minn;
                res_length++;
            }
        }
        // printf("res_length=%d\n", res_length);
        return DP[res_length-1].second;
    }
};

int main() {
    vector<string> input = {"w","wo","wor","worl","world"};
    vector<string> input2 = {"a","banana","app","appl","ap","apply","apple"};
    vector<string> input3 = {"m","mo","moc","moch","mocha","l","la","lat","latt","latte","c","ca","cat"};
    Solution s = Solution();
    cout<<s.longestWord(input)<<endl;
    cout<<s.longestWord(input2)<<endl;
    cout<<s.longestWord(input3)<<endl;
    return 0;
}