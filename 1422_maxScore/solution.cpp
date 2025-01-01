#include <string>

using namespace std;

class Solution {
public:
    int maxScore(string s) {
        int length = s.size();
        int DP[length+1];

        int num1 = 0;
        for (int i = 0; i < length; ++i)
            if (s[i]=='1')
                num1++;

        int score = 0;
        int max_score_idx = 0;
        DP[0] = num1;

        for (int i = 1; i <= length; ++i) {
            int cur_score = DP[i-1];
            if (s[i-1]=='1')
                cur_score--;
            else
                cur_score++;
            if (cur_score > score) {
                score = cur_score;
                max_score_idx = i;
            }
            DP[i] = cur_score;
        }
        if (score == length && (max_score_idx == 0) || (max_score_idx == length))
            score--;
        return score;
    }
};