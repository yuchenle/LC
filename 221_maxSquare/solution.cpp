#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int numRow = matrix.size();
        int numCol = matrix[0].size();
        // if (numRow == 1 || numCol == 1)
        //     return 1;

        int ret = 0;
        int DP[numRow][numCol];
        for (int i = 0; i < numRow; ++i) {
            for (int j = 0; j < numCol; ++j) {
                if (i == 0 || j == 0) {
                    int val = (int) (matrix[i][j] == '1');
                    DP[i][j] = val;
                } else {
                    if (matrix[i][j] == '0') {
                        DP[i][j] = 0;
                    } else if (DP[i-1][j-1] == 0 || DP[i-1][j] == 0 || 0 == DP[i][j-1]) {
                        DP[i][j] = 1;
                    } else if (DP[i-1][j-1] == DP[i-1][j] && DP[i-1][j-1] == DP[i][j-1]) {
                        DP[i][j] = DP[i-1][j-1] + 1;
                    }else{
                        DP[i][j] = std::min({DP[i-1][j-1], DP[i-1][j], DP[i][j-1]}) + 1;
                    }
                }
                if (DP[i][j] > ret)
                    ret = DP[i][j];
                // printf("DP[%d][%d] is %d\n", i,j,DP[i][j]);
            }
        }

        // for (int i = 0; i < numRow; ++i) {
        //     for (int j = 0; j < numCol; ++j) {
        //        cout << DP[i][j] << ' ';
        //     }
        //     cout << endl;
        // }

        return ret*ret;
    }
};

int main(){
    vector<vector<char>> matrix = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    vector<vector<char>> mat2 = {{'0','1'},{'1','0'}};
    vector<vector<char>> mat3 = {{'0'}};
    Solution s = Solution();
    cout<<s.maximalSquare(matrix)<<endl;
    cout<<s.maximalSquare(mat2)<<endl;
    cout<<s.maximalSquare(mat3)<<endl;
    return 0;
}