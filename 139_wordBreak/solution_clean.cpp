#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:

    bool wordBreak(string s, vector<string>& wordDict) {        
        vector<string> wordsInS;
        int sLength = s.size();
        cout << "calling wordBreak with " << s << " with a length of " << sLength << endl;
        for (auto w : wordDict) {
            if (s.find(w) != std::string::npos) {
                wordsInS.push_back(w);
            }
        }

        if (wordsInS.empty())
            return false;

        for (auto w : wordsInS) {
            cout << "word " << w << " is in S and the dictionary" << endl;
        }

        for (auto c : s) {
            bool notIn = true;
            for (auto w : wordsInS) {
                if (w.find(c) != std::string::npos)
                    notIn &= false;
            }
            if (notIn) {
                return false;
            }
        }

        stack<pair<string, int>> myStack;
        myStack.push({s,s.size()});
        bool ret = false;
        bool impossible;
        while (!myStack.empty()) {
            pair<string,int> pp = myStack.top();
            myStack.pop();
            impossible = true;
            cout << "analyzing " << pp.first << " in the stack, there are " << myStack.size() << " elements remaining in the stack" <<  endl;
            for (auto w : wordsInS) {
                int wLength = w.size();
                // the word is longer than the remaining string
                if (wLength > pp.second) {
                    bool notFound = (w.find(pp.first) == std::string::npos);
                    impossible &= notFound;
                    printf("notFound is %d, impossible is %d\n", notFound, impossible);
                    continue;
                }
                int pos = pp.first.find(w);
                if (pos == 0) {
                    impossible &= false;
                    string strRemained = pp.first.substr(wLength+pp.first.find(w), pp.second - wLength);
                    int lengthRemained = pp.second - wLength;
                    printf("strRemained = %s and lengthRemained is %d\n", strRemained.c_str(), lengthRemained);
                    if (lengthRemained == 0) {
                        ret = true;
                        return ret;
                    }
                    printf("pushing element to the stack, stringRemained is %s, lengthRemained is %d\n", strRemained.c_str(), lengthRemained);
                    myStack.push({strRemained, lengthRemained});
                } else {
                    if (pos != std::string::npos)
                        impossible &= false;
                    continue;
                }
            }
            if (impossible)
                return false;
        }
        return ret;
    }
};

int main() {
    Solution s = Solution();
    vector<string> dic1 = {"leet", "code"};
    vector<string> dic2 = {"apple","pen"};
    vector<string> dic3 = {"cats","dog","sand","and","cat"};
    vector<string> dic4 = {"bc","ca"};
    vector<string> dic5 = {"cc","bc","ac","ca"};
    vector<string> dic6 = {"abbcbda","cbdaaa","b","dadaaad","dccbbbc","dccadd","ccbdbc","bbca","bacbcdd","a","bacb","cbc","adc","c","cbdbcad","cdbab","db","abbcdbd","bcb","bbdab","aa","bcadb","bacbcb","ca","dbdabdb","ccd","acbb","bdc","acbccd","d","cccdcda","dcbd","cbccacd","ac","cca","aaddc","dccac","ccdc","bbbbcda","ba","adbcadb","dca","abd","bdbb","ddadbad","badb","ab","aaaaa","acba","abbb"};
    vector<string> dic7 = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
    vector<string> dic8 = {"a","abc","b","cd"};
    vector<string> dic9 = {"cats","dog","sand","and","cat","an"};
    vector<string> dic10 = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
    vector<string> dic11 = {"aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa","ba"};
    // cout << (int)s.wordBreak("leetcode", dic1) << endl;
    // cout << (int)s.wordBreak("applepenapple", dic2) << endl;
    // cout << (int)s.wordBreak("catsandog", dic3) << endl;
    // cout << (int)s.wordBreak("cbca", dic4) << endl;
    // cout << (int)s.wordBreak("acccbccb", dic5) << endl;
    // cout << (int)s.wordBreak("acaaaaabbbdbcccdcdaadcdccacbcccabbbbcdaaaaaadb", dic6) << endl;
    // cout << (int)s.wordBreak("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab", dic7) << endl; // expect false
    // cout << (int)s.wordBreak("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",dic10) << endl; // expect true
    // cout << (int)s.wordBreak("abcd", dic8) << endl;   // expect true
    // cout << (int)s.wordBreak("catsandogcat", dic9) << endl; // expect true
    cout << (int)s.wordBreak("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaabaaaaaaaaaaaaaaaaaaaaaa", dic11) << endl;


    return 0;
}