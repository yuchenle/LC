#include <map>
#include <vector>
#include <iostream>
#include <assert.h>

using namespace std;

class Solution {
public:

    bool biggerThanAll(int val, int idx, vector<int>& arr) {
        assert(idx < arr.size());
        for (int i = idx; i < arr.size(); ++i)
            if (arr[i]<val)
                return false;
        return true;
    }

    int maxChunksToSorted(vector<int>& arr) {
        int length = arr.size();
        if (length == 1)
            return 1;

        bool merged[length];
        for (int i = 0; i < length; ++i)
            merged[i] = false;

        int idx = 0;
        unordered_map<int, int> value_index;
        int arrID = 1;
        for (int i = 0; i < length; ++i) {
            value_index[arr[i]] = i;
        }

        vector<pair<int,int>> listArr;
        for (int i = 0; i < length; ++i) {
            // printf("i=%d\n",i);
            if (merged[i]) {
                if (merged[arr[i]]) {
                    // printf("case 1 \n");
                    continue;
                } else {
                    for (auto &pp : listArr) {
                        if (pp.first <= i && pp.second>=i) {
                            pp.second = arr[i];
                            int upperbound = max(arr[i], value_index[i]);
                            // printf("case 2, upperbound = %d\n", upperbound);
                            for (int j = pp.first; j <= upperbound; ++j)
                                merged[j] = 1;
                            // printf("extended\n");
                        }
                    }
                    // printf("case 2 \n");
                }
            } else {
                if ((i == arr[i]) && biggerThanAll(i, i, arr)) {
                    // printf("case 3\n");
                    listArr.push_back({i,i});
                    merged[i] = 1;
                } else {
                    int upperbound = max(arr[i], value_index[i]);
                    listArr.push_back({i, upperbound});
                    for (int j = i; j <= upperbound; ++j) {
                        merged[j] = 1;
                    }
                    // printf("case 4, first = %d, second = %d\n", i, upperbound);
                }
            }
        }

        return listArr.size();
    }
};

int main() {
    Solution s = Solution();
    // vector<int> input = {1,0,2,3,4};
    // vector<int> input2 = {1,3,0,2,4};
    // vector<int> input3 = {1,4,0,2,3,5};
    // vector<int> input4 = {2,6,1,3,0,5,4};
    vector<int> input5 = {2,0,4,6,3,1,7,5,8};

    // cout<<s.maxChunksToSorted(input)<<endl;
    // cout<<s.maxChunksToSorted(input2)<<endl;
    // cout<<s.maxChunksToSorted(input3)<<endl;
    // cout<<s.maxChunksToSorted(input4)<<endl;
    cout<<s.maxChunksToSorted(input5)<<endl;

    return 0;
}