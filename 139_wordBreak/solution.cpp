#include <iostream>
#include <vector>
#include <string>

using namespace std;

// assuming charToInt is only used
// for english characters not symbols
inline int charToInt(char x) {
    x = std::tolower(x);
    return x-97;
}

class TRIENode {
private:
    char c = '\0';
public:
    char getC() {
        return this->c;
    }

    TRIENode *vv[26] = {0};
    bool isR = false;
    bool isW = false;

    bool isRoot() {
        return isR;
    }

    bool isWord() {
        return isW;
    }

    TRIENode(char w) {
        this->c=w;
    }

    TRIENode(bool isR, bool isW, char w='\0') {
        this->isR = isR;
        this->isW = isW;
        c = w;
    }

    void printFromMe() {
        TRIENode *parseNode = this;
        TRIENode *prevNode = nullptr;
        string s="";
        for (int i = 0; i < 26; ++i) {
            prevNode = this;
            parseNode = vv[i];
            while(parseNode!=nullptr) {
                s+=parseNode->c;
                parseNode = 0;
            }
        }
    }
};

vector<string> printFromMe(TRIENode *node) {
    // printf("node = %p, c = %c\n", node, node->getC());
    vector<string> ret_vec;

    if (node->isWord())
        ret_vec.push_back(std::string()+node->getC());
    for (int i = 0; i < 26; ++i) {
        if (node->vv[i]!=nullptr) {
            vector<string> ch_vec = printFromMe(node->vv[i]);
            for (auto word : ch_vec) {
                ret_vec.push_back(word.insert(0,1,node->getC()));
            }
        }
    }
    return ret_vec;
}

vector<string> printFromMeIterative(TRIENode *root) {
    vector<string> ret_vec;

    // Stack to hold pairs of node pointers and the accumulated word
    stack<pair<TRIENode*, string>> node_stack;

    // Start from the root node
    node_stack.push({root, ""});

    while (!node_stack.empty()) {
        auto [current_node, current_word] = node_stack.top();
        node_stack.pop();

        // If the current node is not the root, update the current word
        if (!current_node->isRoot()) {
            current_word += current_node->getC();
        }

        // If the current node is a word, add it to the result vector
        if (current_node->isWord()) {
            ret_vec.push_back(current_word);
        }

        // Iterate over all possible child nodes (assuming lowercase letters)
        for (int i = 25; i >= 0; --i) { // Reverse order if you want lex order
            if (current_node->vv[i] != nullptr) {
                node_stack.push({current_node->vv[i], current_word});
            }
        }
    }

    return ret_vec;
}


class Solution {
public:

    TRIENode* treeFromDic(vector<string>& dic) {
        TRIENode *root = new TRIENode(true/*isRoot*/, false/*isWord*/);
        TRIENode *presentNode;
        TRIENode *prevNode;
        for (auto s : dic) {
            presentNode = root;
            prevNode = root;
            for (auto ch : s) {
                if (presentNode->vv[charToInt(ch)]==nullptr) {
                    TRIENode *newNode;
                    if (ch == s[s.size()-1])
                        newNode = new TRIENode(false, true, ch);
                    else 
                        newNode = new TRIENode(ch);
                    presentNode->vv[charToInt(ch)] = newNode;
                }
                presentNode = presentNode->vv[charToInt(ch)];
            }
            presentNode = prevNode;
        }
        return root;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        // TRIENode *root = treeFromDic(wordDict);

        // int stringLength = s.size();
        // int numWords = wordDict.size();
        // if (numWords==1) {
        //     return (wordDict[0].compare(s) == 0);
        // }

        // vector<string> words= printFromMe(root);
        // vector<string> words2 = printFromMeIterative(root);

        // for (auto word : words) {
        //     cout << word << endl;
        // }

        for (auto word:words2) {
            cout << word << endl;
        }

        return false;
    }
};

int main() {
    Solution s = Solution();
    vector<string> dic1 = {"leet", "code", "coda", "leetcode","leetcoda"};
    vector<string> dic2 = {"leetcode"};
    cout << (int)s.wordBreak("leetcode", dic1) << endl;
    return 0;
}