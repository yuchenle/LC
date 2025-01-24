#include <vector>

using namespace std;

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        auto beg = arr.begin();
        int length = arr.size();
        vector<int> copy;
        for (int i = 0; i < length; ++i) {
            if (arr[i]==0) {
                copy.push_back(arr[i]);
                copy.push_back(0);
            } else {
                copy.push_back(arr[i]);
            }
        }

        for (int i = 0; i < length; ++i)
            arr[i] = copy[i];

        // for (int i= 0; i < length; ++i) {
        //     printf("%d ", arr[i]);
        // }
        // printf("\n");
        return;
    }
};

int main() {
    Solution s = Solution();
    vector<int> input = {1,0,2,3,0,4,5,0};
    s.duplicateZeros(input);
    return 0;
}