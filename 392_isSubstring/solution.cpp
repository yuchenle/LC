/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int length1 = s.size();
        int length2 = t.size();
        int DP[length1][length2] = {0};


        for (int i = 0; i < length1; ++i)
            for (int j = 0; j < length2; ++j) {
                if (i==0) {
                    string subt = t.substr(0, j+1);
                    if (subt.find(s[i]) != string::npos)
                        DP[i][j] = 1;
                    continue;
                }
                if (i>j) {
                    DP[i][j] = 0;
                    continue;
                }
                
                if (i==j) {
                    string subs = s.substr(0,i+1);
                    string subt = t.substr(0,j+1);
                    DP[i][j] = (subs==subt);
                    continue;
                }
                
                if (DP[i][max(0,j-1)] == 1) {
                    DP[i][j] = 1;
                    continue;
                }
                
                if (DP[max(0,i-1)][max(0,j-1)] == 1) {
                    DP[i][j] = (s[i]==t[j]);
                    continue;
                }
            }
        
        /*    
        for (int i = 0; i < length1; ++i) {
            for (int j = 0; j < length2; ++j) {
                printf("DP[%d][%d] = %d\n",i,j, DP[i][j]);
            }
        }
        */
        
        return DP[length1-1][length2-1];
    }
};


int main()
{
    Solution s = Solution();
    int res = s.isSubsequence("axc", "ahbgdc");
    cout<<"Result is " << res << endl;

    return 0;
}