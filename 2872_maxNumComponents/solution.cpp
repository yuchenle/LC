#include <vector>
#include <iostream>
#include <stack>
#include <map>
#include <unordered_set>

using namespace std;

class Solution {
public:

    bool isValid (int n, vector<vector<int>>& edges, vector<int>& values, int k, int *numComp) {
        // printf("calling isValid with edges.size() = %zu\n", edges.size());
        int length_edges = edges.size();
        unordered_map<int, vector<int>> connected_nodes;
        unordered_map<int, int> nodeToComp;
        unordered_map<int, int> compToSum;

        for (int i = 0; i < n; ++i)
            nodeToComp[i] = -1;

        // from edges, build connected nodes
        for (int i = 0; i < length_edges; ++i) {
            int source = edges[i][0];
            int end = edges[i][1];
            connected_nodes[source].push_back(end);
            connected_nodes[end].push_back(source);
        }

        int idxComp = 0;
        for (int i = 0; i < n; ++i) {
            if (nodeToComp[i]!=-1) {
                continue;
            } else {
                stack<int> toParse;
                unordered_set<int> parsed;

                toParse.push(i);
                while(!toParse.empty()) {
                    int node = toParse.top();
                    toParse.pop();

                    if (parsed.find(node) != parsed.end())
                        continue;

                    parsed.insert(node);

                    if (nodeToComp[node] == -1) {
                        nodeToComp[node] = idxComp;
                        // printf("1parsing node %d, adding to set %d\n", node, idxComp);
                        compToSum[idxComp] += values[node];
                        idxComp++;
                    } else {
                        int myComp = nodeToComp[node];
                        // printf("2parsing node %d, adding to set %d\n", node, myComp);
                        compToSum[myComp] += values[node];
                    }
                    for (int connected : connected_nodes[node]) {
                        nodeToComp[connected] = nodeToComp[node];
                        toParse.push(connected);
                    }
                }
            }
        }

        *numComp = compToSum.size();
        for (auto elem : compToSum) {
            // printf("for set %d, the sum is %d\n", elem.first, elem.second);
            if (elem.second % k != 0) {
                return false;
            }
        }

        return true;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        int length_edges = edges.size();
        unordered_map<int, vector<int>> connected_nodes;

        // from edges, build connected nodes
        // for (int i = 0; i < length_edges; ++i) {
        //     int source = edges[i][0];
        //     int end = edges[i][1];
        //     connected_nodes[source].push_back(end);
        // }

        // if no edge connected to a node, set its connected_node to empty
        // for (int i = 0; i < n; ++i)
        //     if (connected_nodes.find(i) == connected_nodes.end())
        //         connected_nodes[i] = {};

        // adding the edges one by one, from empty
        long long begin = (1 << length_edges) - 1;
        int numComp = 0;

        for (long long i = 0; i <= begin; ++i) {
            printf("i=%lld\n", i);
            vector<vector<int>> tmp;
            for (int j = 0; j < length_edges; ++j) {
                if (1&(i>>j)) {
                    // add the edge
                    tmp.push_back(edges[j]);
                }
            }
            if (isValid(n, tmp, values, k, &numComp))
                return numComp;
        }
        return -1;
    }
};

int main() {
    Solution s = Solution();
    // vector<vector<int>> edges = {{0,2},{1,2},{1,3},{2,4}};
    // vector<int> values = {1,8,1,4,4};
    // int numComp = 0;

    // int maxComp = s.maxKDivisibleComponents(5, edges, values, 6);

    // vector<vector<int>> edges = {{0,1}, {0,2}, {1,3}, {1,4}, {2,5}, {2,6}};
    // vector<int> values = {3,0,6,1,5,2,1};
    // int maxComp = s.maxKDivisibleComponents(7, edges, values, 3);

    vector<vector<int>> edges = {{39,37},{39,34},{34,22},{22,45},{34,38},{22,52},{22,42},{22,14},{34,7},{39,51},{39,9},{52,50},{37,47},{38,27},{42,44},{7,0},{51,32},{50,53},{5,18},{18,6},{5,49},{5,1},{1,46},{1,3},{46,17},{18,4},{6,28},{6,21},{34,6},{8,48},{48,31},{8,16},{48,2},{8,12},{2,35},{31,43},{16,20},{2,26},{16,30},{31,40},{30,41},{42,12},{23,19},{23,54},{23,13},{19,36},{23,24},{23,25},{24,10},{23,29},{10,33},{23,11},{24,15},{45,33}};
    vector<int> values = {343755,691686,311362,176061,6530946,2217681,2218800,781368,417495,2502426,3711249,1039152,354854,1635858,293427,2969805,267671,1656138,1312059,460260,58057,1373532,404955,2833431,1075521,261960,162865,171078,573210,1587567,588491,30276,967644,1192980,305772,697041,758190,4829079,1177167,935895,2516313,35462,173844,704055,244920,641457,410319,417894,311195,2204979,870675,2913804,1390251,6455137,1839438};
    int maxComp = s.maxKDivisibleComponents(55, edges, values, 6455137);
    cout << "there are " << maxComp << " components" << endl;
}