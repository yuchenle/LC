#include <string>
#include <unordered_map>

using namespace std;

class Solution {
    unordered_map<char, int>mm;
    Solution () {
        mm['I']=1;
        mm['V']=5;
        mm['X']=10;
        mm['L']=50;
        mm['C']=100;
        mm['D']=500;
        mm['M']=1000;
    }
public:
    int romanToInt(string s) {
        


        int ret = 0;
        int length = s.size();

        for (int i = 0; i < length; ++i) {
            ret+=mm[s[i]];
            if (i!=0) {
                if ((s[i]=='V' || s[i]=='X') && s[i-1]=='I')
                    ret-=1;
                if ((s[i]=='L' || s[i]=='C') && s[i-1]=='X')
                    ret-=10;
                if ((s[i]=='D' || s[i]=='M') && s[i-1]=='C')
                    ret-=100;
            }
        }
        return ret;
    }
};