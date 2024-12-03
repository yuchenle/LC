class Solution {
public:
    int minOperations(vector<string>& logs) {
        int level = 0;
        for (auto str : logs) {
            if (str.compare("../")==0)
                level = max(level-1,0);
            else if (str.compare("./"))
                level += 1;
        }
        return (max(level,0));
    }
};