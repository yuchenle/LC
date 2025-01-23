#include <vector>

using namespace std;

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int numRows = grid.size();
        int numCols = grid[0].size();
        vector<pair<int,int>> ones;
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                if (grid[i][j]==1) {
                    ones.push_back({i,j});
                    printf("1 = %d, %d\n", i, j);
                }
            }
        }

        int ret = 0;
        for (auto elem: ones) {
            if (grid[elem.first][elem.second]==1) {
                for (int i = 0; i < numRows; ++i) {
                    if (grid[i][elem.second]==1) {
                        if (i!=elem.first) {
                            ret++;
                            grid[i][elem.second]=0;
                            printf("counting [%d,%d]\n", i, elem.second);
                        }
                    }
                }
                for (int i = 0; i < numCols; ++i) {
                    if (grid[elem.first][i]==1) {
                        if (i!=elem.second) {
                            ret++;
                            grid[elem.first][i]=0;
                            printf("counting [%d,%d]\n", elem.first, i);
                        }
                    }
                }
                grid[elem.first][elem.second]=0;
            }
        }
        return ret;
    }
};

int main() {
    Solution s = Solution();
    vector<vector<int>> input = {{1,0},{0,1}};
    vector<vector<int>> input2 = {{1,0},{1,1}};
    s.countServers(input2);
    return 0;
}