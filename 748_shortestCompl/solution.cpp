
class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        unordered_map<char, int> mm;
        int lengthP = licensePlate.size();
        int lengthW = words.size();
        std::transform(licensePlate.begin(), licensePlate.end(), licensePlate.begin(), ::tolower);
        for (int i = 0; i < lengthP; ++i) {
            char cc = licensePlate[i];
            if(cc <= 'z' && cc >= 'a')
                mm[cc]++;
        }

        int toVerif = mm.size();
        
        string ret = "";
        size_t smallestS = 99;
        for (auto word : words) {
            unordered_map<char,int> sm;
            vector<char> parsed={};
            int verified=0;
            for (char cc : word) {
                if(cc <= 'z' && cc >= 'a') {
                  sm[cc]++;
                  if (mm[cc]>=1 && sm[cc]>=mm[cc] && (std::find(parsed.begin(), parsed.end(), cc) == parsed.end())) {
                    verified++;
                    parsed.push_back(cc);
                  }
                }
            }
            if (verified==toVerif && word.size() < smallestS) {
                ret = word;
                smallestS = word.size();
            }
        }
        return ret;
    }
};