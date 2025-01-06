#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int length = boxes.size();
        vector<int> ones;
        for (int i = 0; i < length; ++i) {
            if (boxes[i]=='1') {
                ones.push_back(i);
            }
        }
        // for (int i = 0; i < ones.size(); ++i) printf("1 at %d\n", ones[i]);
        vector<int> ret;
        for (int i = 0; i < length; ++i) {
            int sum = 0;
            for (int j = 0; j < ones.size(); ++j) {
                if (ones[j]!=i) {
                    sum += abs(ones[j]-i);
                }
            }
            ret.push_back(sum);
        }
        return ret;
    }
};

int main() {
    string input = "110";
    Solution s = Solution();
    auto res = s.minOperations(input);
    for (auto ii : res) {
        printf("%d ", ii);
    }
    printf("\n");
    return 0;
}