#include <vector>
#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        int length = pairs.size();
        int numPeople = n;
        vector<int> ret_vec;
        int ret = 0;
        if (n==2) {
            return 0;
        }

        unordered_map<int,int> paired_;
        for (int i = 0; i < length; ++i) {
            int me = pairs[i][0];
            int p_f = pairs[i][1];
            paired_[me] = p_f;
            paired_[p_f] = me;
        }

        int my_idx;
        for (int i = 0; i < numPeople; ++i) {
            auto parsed = std::find(ret_vec.begin(), ret_vec.end(), i);
            if (parsed != ret_vec.end())
                continue;

            int me = i;
            int pair_ = paired_[me];
            bool end = false;
            if (preferences[me][0]==pair_)
                continue;


            for (int fr : preferences[me]) {
                if (end)
                    break;
                if (fr == pair_)
                    break;
                int its_pair = paired_[fr];
                
                if (its_pair == preferences[fr][0])
                    continue;
                else {
                    int fr_pair_idx = -1;
                    for (int j = 0; j < numPeople-1; ++j) {
                        if (preferences[fr][j] == me) {
                            my_idx = j;
                            if (fr_pair_idx==-1) {
                                ret ++;
                                ret_vec.push_back(me);
                                end = true;
                            }
                            break;
                        } else if (preferences[fr][j] == its_pair)
                            fr_pair_idx = j;
                    }
                }
            }
        }
        return ret;
    }
};

int main() {
    Solution s = Solution();
    vector<vector<int>> fr1 = {{1,2,3},{3,2,0},{3,1,0},{1,2,0}};
    vector<vector<int>> fr2 = {{1,4,3,2,5},{0,5,4,3,2},{3,0,1,5,4},{2,1,4,0,5},{2,1,0,3,5},{3,4,2,0,1}};
    vector<vector<int>> p1 = {{0,1},{2,3}};
    vector<vector<int>> p2 = {{3,1},{2,0},{5,4}};
    cout<<s.unhappyFriends(6,fr2,p2)<<endl;
    return 0;
}