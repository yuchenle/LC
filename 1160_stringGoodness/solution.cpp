class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> mm;
        for(char c : chars) {
            mm[c]++;
        }

        int ret = 0;
        for (string& s : words) {
            unordered_map<char, int> mm_copy(mm);
            string building = "";
            for (char& c : s) {
                if (mm_copy[c]) {
                    mm_copy[c]--;
                    building += c;
                } else {
                    building = "";
                    break;
                }
            }
            ret += building.size();
        }
        return ret;
    }
};