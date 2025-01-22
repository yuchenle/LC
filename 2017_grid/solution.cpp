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

    pair<long long, vector<pair<int,int>>> firstInter(vector<vector<int>>& grid) {
        int length = grid[0].size();
        int dp[length];
        long long cur_min = 9999999;
        int pos_to_down;
        for (int i = 0; i < length; ++i) {
            long long firstRowRem = sumToRight(grid, 0, i, length);
            long long secondRowRem = sumToRight(grid, 1, 0, i);
            // printf("firstrowrem = %lld, secondrowrem = %lld\n", firstRowRem, secondRowRem);
            if (max(firstRowRem, secondRowRem) < cur_min) {
                cur_min = max(firstRowRem, secondRowRem);
                pos_to_down = i;
            }
        }
        pair<long long, vector<pair<int,int>>> ret = {cur_min,{{0,0}}};
        for (int i = 1; i <= pos_to_down; ++i) {
            ret.second.push_back({0,i});
        }
        // ret.push_back({1,pos_to_down});
        for (int i = pos_to_down; i < length; ++i) {
            ret.second.push_back({1, i});
        }
        return ret;
    }

    // pair<int, vector<pair<int,int>>> interm(vector<vector<int>>& grid) {
    //     int numRows = grid.size();
    //     int numCols = grid[0].size();
    //     pair<int, vector<pair<int,int>>> DP[numRows][numCols];
    //     DP[0][0] = {grid[0][0],{{0,0}}};
    //     for (int i = 0; i < numRows; ++i) {
    //         for (int j = 0; j < numCols; ++j) {
    //             if (i==0&&j==0)
    //                 continue;
    //             int leftV = 0;
    //             int upperV = 0;
    //             int val = 0;

    //             upperV = grid[i][j] + DP[max(i-1,0)][j].first;
    //             leftV = grid[i][j] + DP[i][max(j-1,0)].first;

    //             if (leftV > upperV) {
    //                 val = leftV;
    //                 vector<pair<int,int>> v2(DP[i][max(0,j-1)].second);
    //                 v2.push_back({i,j});
    //                 DP[i][j] = {val, v2};
    //             } else {
    //                 val = upperV;
    //                 vector<pair<int,int>> v2(DP[max(0,i-1)][j].second);
    //                 v2.push_back({i,j});
    //                 DP[i][j] = {val, v2};
    //             }
    //         }
    //     }
    //     // cout << "the val is " << DP[numRows-1][numCols-1].first << endl;
    //     // for (auto elem : DP[numRows-1][numCols-1].second) {
    //     //     printf("%d, %d\n", elem.first, elem.second);
    //     // }
    //     return DP[numRows-1][numCols-1];
    // }

    long long gridGame(vector<vector<int>>& grid) {
        int numRows = grid.size();
        int numCols = grid[0].size();

        auto ret = firstInter(grid);
        for (auto elem : ret.second) {
            printf("222--->%d; %d\n", elem.first, elem.second);
            // grid[elem.first][elem.second] = 0;
        }
        return ret.first;

        // for (int i = 0; i < numRows; ++i) {
        //     for (int j = 0; j < numCols; ++j) {
        //         printf("grid[%d][%d] = %d\n", i, j, grid[i][j]);
        //     }
        // }
        
        // auto rett = interm(grid);
        // return rett.first;
        // return 0;
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