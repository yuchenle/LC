#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int length = grid.size();
        unordered_map<int, vector<int>> hashtab;
        for (int i = 0; i < length; ++i) {
            hashtab[grid[i][0]].push_back(i);
        }

        int ret = 0;
        for (int col = 0; col < length; ++col) {
            vector<int> rows_to_check = hashtab[grid[0][col]];
            for (auto row_id : rows_to_check) {
                bool equal = true;
                for (int j = 0; j < length; ++j) {
                    if (grid[j][col] != grid[row_id][j]) {
                        equal = false;
                        break;
                    }
                }
                ret += equal;
            }
        }
        return ret;
    }
};

int main() {
    Solution s = Solution();
    vector<vector<int>> input = {{3,2,1},{1,7,6},{2,7,7}};
    vector<vector<int>> input2 = {{3,1,2,2},{1,4,4,5},{2,4,2,2},{2,4,2,2}};
    cout << s.equalPairs(input) << endl;
    cout << s.equalPairs(input2) << endl;
    return 0;
}