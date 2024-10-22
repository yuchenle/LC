#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:

    void printDP(pair<int,int> **DP, int m, int n) {
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                printf("%d ", DP[i][j].first);
            }
            printf("\n");
        }
        printf("\n");
    }

    int countSquares(vector<vector<int>>& matrix) {
        int numRow = matrix.size();
        int numCol = matrix[0].size();

        pair<int,int> **DP = (pair<int,int> **)malloc(sizeof(pair<int,int> *) * numRow);
        for (int i = 0; i < numRow; ++i) {
            DP[i] = (pair<int,int> *)calloc(numCol, sizeof(pair<int,int>));
        }

        for (int i = 0; i < numRow; ++i) {
            for (int j = 0; j < numCol; ++j) {
                if (i==0) {
                    if (j==0)
                        DP[i][j] = {matrix[i][j], matrix[i][j]==1};
                    else
                        DP[i][j] = {matrix[i][j] + DP[i][j-1].first, matrix[i][j]==1};
                    continue;
                }

                if (j==0) {
                    if (i!=0) {
                        DP[i][j] = {matrix[i][j] + DP[i-1][j].first, matrix[i][j]==1};
                        continue;
                    }
                }

                DP[i][j].first = DP[i-1][j].first - DP[i-1][j-1].first + DP[i][j-1].first + matrix[i][j];
                if (matrix[i][j]==0)
                    DP[i][j].second=0;
                else
                    DP[i][j].second = min(min(DP[i-1][j-1].second, DP[i-1][j].second), DP[i][j-1].second)+1;
                if (DP[i][j].second!=0)
                    DP[i][j].first += DP[i][j].second-1;
            }
        }
        // printDP(DP, numRow, numCol);
        return DP[numRow-1][numCol-1].first;
    }
};

int main() {
    Solution s = Solution();
    vector<vector<int>> mat1 = {{0,1,1,1},{1,1,1,1},{0,1,1,1}};
    vector<vector<int>> mat2 = {{1,0,1},{1,1,0},{1,1,0}};
    cout<<s.countSquares(mat1)<<endl;
    cout<<s.countSquares(mat2)<<endl;
    return 0;
}