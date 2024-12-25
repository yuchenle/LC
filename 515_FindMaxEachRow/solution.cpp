#include <stack>
#include <vector>
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

using nt = pair<TreeNode *, int>;
class Solution {
public:

    vector<int> BFS(TreeNode *node, TreeNode *parent) {
        vector<int> ret;
        map<int,int> mm; // layer : max(layer)
        std::stack<nt> toParse;
        toParse.push({node->left,1});
        toParse.push({node->right,1});
        while(!toParse.empty()) {
            auto elem = toParse.top();
            toParse.pop();
            TreeNode *parsing = elem.first;

            if (parsing==nullptr)
                continue;

            int layer = elem.second;
            if (mm.find(layer)!=mm.end()) {
                if (mm[layer]<parsing->val)
                    mm[layer] = parsing->val;
            } else {
                mm[layer] = parsing->val;
            }

            toParse.push({parsing->left, layer+1});
            toParse.push({parsing->right,layer+1});
        }

        for (auto elem : mm) {
            ret.push_back(elem.second);
        }

        if (parent==nullptr)
            ret.insert(ret.begin(), node->val);

        return ret;
    }

    vector<int> largestValues(TreeNode* root) {
        if (root==nullptr)
            return {};
        return BFS(root, nullptr);
    }
};