#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int length = prices.size();
        vector<int> ret;
        for (int i = length-1; i >= 0; --i) {
            if (i == length-1) {
                ret.insert(ret.begin(), prices[i]);
            } else {
                bool inserted = false;
                for (int j = i+1; j < length; ++j) {
                    if (prices[j] <= prices[i]) {
                        ret.insert(ret.begin(), prices[i]-prices[j]);
                        inserted = true;
                        break;
                    }
                }
                if (!inserted)
                    ret.insert(ret.begin(), prices[i]);
            }
        }
        // printf("the size of ret is %zu\n", ret.size());
        return ret;
    }
};

int main() {
    Solution s = Solution();
    vector<int> input = {8,4,6,2,3};
    auto ret = s.finalPrices(input);
    for (int i = 0; i < ret.size(); ++i) {
        printf("%d ", ret[i]);
    }
    printf("\n");
    return 0;
}