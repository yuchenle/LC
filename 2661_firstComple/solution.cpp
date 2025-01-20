#include <vector>
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int, pair<int,int>> mm;
        int numRows = mat.size();
        int numCols = mat[0].size();

        int cnt_rows[numRows];
        for (int i = 0; i < numRows; ++i) {
            cnt_rows[i] = numCols; // each row has numCols elements unpainted
        }

        int cnt_cols[numCols];
        for (int i = 0; i < numCols; ++i) {
            // each column has numRows elements
            cnt_cols[i] = numRows;
        }

        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                mm[mat[i][j]] = {i,j};
            }
        }

        for (int i = 0; i < arr.size(); ++i) {
            int idx_i = mm[arr[i]].first;
            int idx_j = mm[arr[i]].second;
            cnt_rows[idx_i]--;
            cnt_cols[idx_j]--;
            if ((cnt_rows[idx_i]==0) || (cnt_cols[idx_j]==0))
                return i;
        }
        return 0;
    }
};

int main() {
    Solution s = Solution();
    vector<int> input1 = {1,3,4,2};
    vector<vector<int>> input2 = {{1,4},{2,3}};
    cout<<s.firstCompleteIndex(input1,input2)<<endl;
    return 0;
}