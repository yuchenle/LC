#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int numRows = grid.size();
        int numCols = grid[0].size();
        vector<pair<int,int>> ones;
        int ret = 0;
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                if (grid[i][j]==1) {
                    queue<pair<int,int>> qq;
                    qq.push({i,j});
                    int parsed=0;
                    while(!qq.empty()){
                        auto elem = qq.front();
                        qq.pop();
                        // printf("parsing [%d,%d]\n", elem.first,elem.second);
                        parsed++;
                        bool found=0;
                        for (int row = 0; row < numRows; ++row) {
                            if ((grid[row][elem.second]==1)&&
                                (row!=elem.first)) {
                                found = 1;
                                grid[row][elem.second]=0;
                                qq.push({row,elem.second});
                            }
                        }
                        for (int col = 0; col < numCols; ++col) {
                            if ((grid[elem.first][col]==1)&&
                                (col!=elem.second)) {
                                found = 1;
                                grid[elem.first][col]=0;
                                qq.push({elem.first,col});
                            }
                        }
                        if (found) {
                            // ret++;
                            grid[elem.first][elem.second]=0;
                            // printf("[%d,%d]=1, counting it\n", elem.first, elem.second);
                        }
                    }
                    if (parsed>1) {
                        ret+=parsed;
                    }
                }
            }
        }
        return ret;
    }
};

int main() {
    Solution s = Solution();
    vector<vector<int>> input = {{1,0},{0,1}};
    vector<vector<int>> input2 = {{1,0},{1,1}};
    vector<vector<int>> input3 = {{0,0,0,0},{1,1,1,1},{0,0,0,1},{0,0,1,1},{0,0,0,1}};
    // cout<<s.countServers(input)<<endl;
    // cout<<s.countServers(input2)<<endl;
    cout<<s.countServers(input3)<<endl;
    return 0;
}