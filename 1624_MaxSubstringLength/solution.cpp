class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char, vector<int>> mm;
        int length=s.size();
        for (int i = 0; i < length; ++i) {
            mm[s[i]].push_back(i);
        }

        int ret=-1;
        for (auto elem : mm) {
            int cur_ret = -1;
            auto vec = elem.second;
            auto firstPos = *elem.second.begin();
            //printf("for char %c, firstPos is %d\n", elem.first, firstPos);
            auto lastPos = *(elem.second.end()-1);
            //printf("lastPos is %d\n", lastPos);
            cur_ret = lastPos - firstPos - 1;
            if (cur_ret > ret)
                ret = cur_ret;
        }
        return ret;
    }
};