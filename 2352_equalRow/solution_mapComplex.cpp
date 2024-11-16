class Solution {
public:
    // int equalPairs(vector<vector<int>>& grid) {
    //     ios_base::sync_with_stdio(false);
    //     // cin.tie(NULL);
    //     // cout.tie(NULL);

    //     int n = grid.size();

    //     int pairs = 0;
    //     for(int i  = 0; i < n; i++) {
    //         for(int j = 0; j < n; j++) {

    //             bool isValid = true;
    //             int x = i;
    //             int y = j;
    //             int z = 0;

    //             while(z < n) {
    //                 if(grid[x][z] != grid[z][y]) {
    //                     isValid = false;
    //                     break;
    //                 }
    //                 z++;
    //             }

    //             if(isValid)
    //                 pairs++;
    //         }
    //     }
    //     return pairs;
    // }

    int equalPairs(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        // cout.tie(NULL);

        int n = grid.size();

        map<vector<int>, int> freqMap;
        int pairs = 0;

        for(int j = 0; j < n; j++)
            freqMap[grid[j]]++;

        for(int i  = 0; i < n; i++) {
            vector<int> col;
            for(int j = 0; j < n; j++) {
                col.push_back(grid[j][i]);
            }
            pairs += freqMap[col];
        }

        return pairs;
    }
};