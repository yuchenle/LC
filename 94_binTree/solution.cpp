/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <vector>
#include <map>

using namespace std;

class Solution {
public:

    void dfs(TreeNode* node, TreeNode *parent, vector<int> &curr) {
        if (node->left)
            dfs(node->left, node, curr);

        curr.push_back(node->val);

        if (node->right)
            dfs(node->right, node, curr);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        dfs(root, nullptr, ret);
        return ret;
    }
};

int main() {
    Solution s = Solution();

    TreeNode t3(3);
    TreeNode t2(2, &t3, nullptr);
    TreeNode t1(1, nullptr, &t2);
    s.inorderTraversal(&t1);
}