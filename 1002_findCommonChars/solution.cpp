#include <vector>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int length = words.size();
        int cc[length][26];
        for (int i = 0; i < length; ++i) {
            for (int j = 0; j < 26; ++j) {
                cc[i][j]=0;
            }
        }

        for (int i = 0; i < length; ++i) {
            for (int j = 0; j < words[i].size(); ++j) {
                cc[i][words[i][j]-'a']++;
            }
        }

        int MinAlph[26];
        for (int i = 0; i < 26; ++i) MinAlph[i]=101;

        for (int i = 0; i < length; ++i) {
            for (int j = 0; j < 26; ++j) {
                if (cc[i][j]<MinAlph[j])
                    MinAlph[j]=cc[i][j];
            }
        }

        vector<string> rett;
        for (int i = 0; i < 26; ++i) {
            rett.insert(rett.end(), MinAlph[i], std::string(1, 'a'+i));
        }
        return rett;
    }
};

int main() {
    Solution s = Solution();
    vector<string> input = {"bella","label","roller"};
    vector<string> ss = s.commonChars(input);
    for (auto elem : ss) {
        printf("%s\n", elem.c_str());
    }
    return 0;
}