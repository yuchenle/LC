#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:

    int findSum(TreeNode *node, unordered_map<int, int>& mm) {
        if (node == nullptr)
            return 0;
        int subSum = node->val;
        subSum += findSum(node->left, mm);
        subSum += findSum(node->right, mm);
        // printf("sum for node %d is %d\n", node->val, subSum);
        mm[subSum]++;
        return subSum;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> mm;
        findSum(root, mm);

        vector<int> ret;
        int mostCommonOcc = 0;
        for (auto elem : mm) {
            if (elem.second > mostCommonOcc) {
                mostCommonOcc = elem.second;
                ret = {};
                ret.push_back(elem.first);
            } else if (elem.second == mostCommonOcc)
                ret.push_back(elem.first);
        }
        // printf("returning from findFrequentTreeSum, mm has %zu elements\n", mm.size());
        return ret;
    }
};

int main() {
    TreeNode t1(2);
    TreeNode t2(-5);
    TreeNode root(5, &t1, &t2);
    Solution s = Solution();
    auto list = s.findFrequentTreeSum(&root);
    for (auto elem : list) {
        printf("%d ", elem);
    }
    printf("\n");
    return 0;
}