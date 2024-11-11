#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
}TN;
 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
        stack<TreeNode*> pile;
        pile.push(root);
        while(pile.size()!=0) {
            printf("pile size is %u\n", pile.size());
            TreeNode *node = pile.top();
            pile.pop();
            if (node==nullptr || isBalanced(node)) {
                continue;
            } else {
                int hleft = height(node->left);
                int hright = height(node->right);
                if (hleft>hright) {
                    printf("doing rotateRight\n");
                    rotateRight(node->left,node);
                    if (node->left->left)
                        pile.push(node->left->left);
                    if (node->left->right)
                        pile.push(node->left->right);
                    pile.push(node->left);
                } else {
                    printf("doing rotateLeft\n");
                    rotateLeft(node,node->right);
                    if (node->right->left)
                        pile.push(node->right->left);
                    if (node->right->right)
                        pile.push(node->right->right);
                    pile.push(node->right);
                }
            }
        }
        return root;
    }
    
    void rotateLeft(TreeNode* n1, TreeNode* n2) {
        TreeNode* tmp = n2->left;
        n2->left = n1;
        n1->right = tmp;
    }
    void rotateRight(TreeNode* n1, TreeNode* n2) {
        TreeNode* tmp = n1->right;
        n1->right = n2;
        n2->left = tmp;
    }

    bool isBalanced(TreeNode* r) {
        if (r==nullptr)
            return true;
        int hleft = height(r->left);
        int hright = height(r->right);
        if (abs(hleft-hright) > 1)
            return false;
        else
            return true;
    }

    int height(TreeNode* node) {
        if (node == nullptr)
            return 0;
        else
            return 1 + std::max(height(node->left),height(node->right));
    }
};

int height(TN *node) {
    if (node==nullptr)
        return 0;
    else
        return 1 + std::max(height(node->left),height(node->right));
}

int main() {
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node11 = new TreeNode(11);

    // Intermediate nodes
    TreeNode* node2 = new TreeNode(2, nullptr, node3);
    TreeNode* node9 = new TreeNode(9, nullptr, node11);
    TreeNode* node12 = new TreeNode(12, node9, nullptr);

    // Higher-level nodes
    TreeNode* node7 = new TreeNode(7, node2, node12);
    TreeNode* node14 = new TreeNode(14, node7, nullptr);
    TreeNode* node17 = new TreeNode(17);
    TreeNode* node15 = new TreeNode(15, node14, node17);

    // Root node
    TreeNode* root = new TreeNode(1, nullptr, node15);
    Solution s = Solution();
    
    s.balanceBST(root);
    
    printf("height of root is %d\n", height(root));
    return 0;
}