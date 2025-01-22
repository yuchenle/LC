#include <vector>
#include <assert.h>
#include <iostream>

using namespace std;

class Solution {
public:

    inline long long sumToRight(vector<vector<int>>& grid, int i, int start_j, int end_j) {
        int length = grid[0].size();
        assert(i <= 1);
        assert(start_j >= 0);
        assert(end_j <= length);
        long long sum = 0;
        for (int pos_j = start_j; pos_j < end_j; ++pos_j) {
            if (pos_j == start_j && i == 0)
                continue;
            sum += grid[i][pos_j];
        }
        return sum;
    }

    long long firstInter(vector<vector<int>>& grid) {
        int length = grid[0].size();
        int dp[length];
        long long cur_min = LLONG_MAX;
        int pos_to_down;
        long long prevFirstRow = sumToRight(grid, 0, 0, length);
        long long prevSecondRow = 0;
        for (int i = 0; i < length; ++i) {
            if (i!=0) {
                prevFirstRow -= grid[0][i];
                prevSecondRow += grid[1][i-1];
            }
            // printf("firstrowrem = %lld, secondrowrem = %lld\n", firstRowRem, secondRowRem);
            if (max(prevFirstRow, prevSecondRow) < cur_min) {
                cur_min = max(prevFirstRow, prevSecondRow);
                pos_to_down = i;
            }
        }
        
        return cur_min;
    }

    long long gridGame(vector<vector<int>>& grid) {
        int numRows = grid.size();
        int numCols = grid[0].size();

        auto ret = firstInter(grid);
        return ret;
    }
};

int main() {
    Solution s = Solution();
    vector<vector<int>> input = {{2,5,4},{1,5,1}};
    vector<vector<int>> input2 = {{20,3,20,17,2,12,15,17,4,15},{20,10,13,14,15,5,2,3,14,3}};
    // cout << s.gridGame(input) << endl;
    cout << s.gridGame(input2) << endl;
    return 0;
}