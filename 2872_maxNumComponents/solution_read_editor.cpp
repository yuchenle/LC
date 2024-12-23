#include <vector>
#include <iostream>
#include <map>

using namespace std;

class Solution {
private:
    int k_v;

public:

    int dfs(int node, unordered_map<int, vector<int>> &connections, vector<int>& values, int *numComp, int parent) {
        // printf("calling dfs with node %d\n", node);
        int sum = values[node];
        for (int neighbor : connections[node]) {
            if (neighbor != parent)
                sum += dfs(neighbor, connections, values, numComp, node);
        }
        if (sum % k_v == 0)
            (*numComp)++;
        return sum % k_v;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        this->k_v = k;
        unordered_map<int, vector<int>> neighbors;
        for (int i = 0; i < edges.size(); ++i) {
            neighbors[edges[i][0]].push_back(edges[i][1]);
            neighbors[edges[i][1]].push_back(edges[i][0]);
        }

        int numComp = 0;
        dfs(0, neighbors, values, &numComp, -1);
        return numComp;
    }
};

int main() {
    Solution s = Solution();
    // vector<vector<int>> edges = {{0,2},{1,2},{1,3},{2,4}};
    // vector<int> values = {1,8,1,4,4};
    // int maxComp = s.maxKDivisibleComponents(5, edges, values, 6);

    vector<vector<int>> edges = {{0,1}, {0,2}, {1,3}, {1,4}, {2,5}, {2,6}};
    vector<int> values = {3,0,6,1,5,2,1};
    int maxComp = s.maxKDivisibleComponents(7, edges, values, 3);
    printf("maxComp = %d\n", maxComp);
    return 0;
}