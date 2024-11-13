#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {printf("1\n");}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {printf("2\n");}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {printf("3\n");}
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
    vector<TreeNode *> getVals(TreeNode *root) {
        if (root == nullptr)
            return vector<TreeNode *>();

        vector<TreeNode *> ret = {root};
        vector<TreeNode *> left = getVals(root->left);
        vector<TreeNode *> right = getVals(root->right);
        ret.insert(ret.end(), left.begin(), left.end());
        ret.insert(ret.end(), right.begin(), right.end());
        return ret;
    }

    vector<int> indexToInsert(int start, int end){
        int length = end-start+1;
        // printf("start = %d, end = %d\n", start, end);
        // if (length<=0)
        //     return vector<int>();

        if (length<=1)
            return {start};
        if (length==2)
            return {start+length/2, start};

        vector<int> ret = {start+length/2};
        vector<int> left = indexToInsert(start, (start + length/2)-1);
        vector<int> right = indexToInsert(start+(length/2)+1, end);
        ret.insert(ret.end(), left.begin(), left.end());
        ret.insert(ret.end(), right.begin(), right.end());
        return ret;
    }

    TreeNode* balanceBST(TreeNode* root) {
        if (isBalanced(root))
            return root;
        vector<TreeNode *> arrayNodes = getVals(root);
        std::sort(arrayNodes.begin(), arrayNodes.end(), [](const TreeNode *a, const TreeNode *b) {
            return a->val < b->val;
        });

        TreeNode *ret = nullptr;

        vector<int> indexToAdd = indexToInsert(0, arrayNodes.size()-1);
        for (auto node : arrayNodes) {
            node->left = nullptr;
            node->right = nullptr;
        }

        // printf("\n");
        // for (auto node : indexToAdd) {
        //     printf("%d ", node);
        // }

        // printf("\n");

        for (auto i : indexToAdd) {
            if (ret==nullptr)
                ret = arrayNodes[i];
            else{
                insert(ret, arrayNodes[i]);
            }
        }


        printf("printing the balanced tree\n");
        vector<TreeNode *> arrayNodes2 = getVals(ret);
        for (auto node : arrayNodes2) {
            printf("%d ", node->val);
        }
        printf("\n");
        return ret;
    }

    void insert(TreeNode *tree, TreeNode *node) {
        if (tree == nullptr || node == nullptr)
            return;
        
        if (tree->val < node->val) {
            if (tree->right==nullptr)
                tree->right = node;
            else
                insert(tree->right, node);
        }
        if (tree->val > node->val) {
            if (tree->left == nullptr)
                tree->left = node;
            else
                insert(tree->left, node);
        }
    }

    bool isBalanced(TreeNode* r) {
        if (r==nullptr)
            return true;
        bool ret;
        int hleft = height(r->left);
        int hright = height(r->right);
        if (abs(hleft-hright) > 1)
            ret = false;
        else
            ret = true;
        ret &= isBalanced(r->left);
        ret &= isBalanced(r->right);
        return ret;
    }

    int height(TreeNode* node) {
        if (node == nullptr)
            return 0;
        else {
            // printf("height: node->val : %d\n", node->val);
            return 1 + std::max(height(node->left),height(node->right));
        }
    }
};

int main() {
    // Leaf nodes
    TreeNode* node9 = new TreeNode(9);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node18 = new TreeNode(18);

    // Intermediate nodes
    TreeNode* node15 = new TreeNode(15, node9, nullptr); // 15 with left child 9
    TreeNode* node17 = new TreeNode(17, node15, node18); // 17 with left child 15 and right child 18
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node6 = new TreeNode(6, node3, nullptr); // 6 with left child 3

    // Second level nodes
    TreeNode* node5 = new TreeNode(5, node2, node6); // 5 with left child 2 and right child 6
    TreeNode* node20 = new TreeNode(20, node17, nullptr); // 20 with left child 17

    // Root node
    TreeNode* root = new TreeNode(8, node5, node20); // 8 with left child 5 and right child 20


    Solution s = Solution();
    cout << " the old root is balanced? " << s.isBalanced(root) << endl;

    TreeNode *newR = s.balanceBST(root);
    cout << " the new root is balanced? " << s.isBalanced(newR) << endl;
    
    return 0;
}