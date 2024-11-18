#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int numRows = grid.size();
        int numCols = grid[0].size();
        if (numRows==1 && numCols==1)
            return grid[0][0]*4;
        int ret = 0;
        for  (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                if (grid[i][j] == 1) {
                    if (i==0)
                        ret++;
                    if (i==numRows-1)
                        ret++;
                    if (j==0)
                        ret++;
                    if (j==numCols-1)
                        ret++;
                    if (grid[max(0,i-1)][j] == 0)
                        ret++;
                    if (grid[min(numRows-1,i+1)][j] == 0)
                        ret++;
                    if (grid[i][max(0,j-1)] == 0)
                        ret++;
                    if (grid[i][min(numCols-1, j+1)] == 0)
                        ret++;
                }
            }
        }
        return ret;
    }
};

