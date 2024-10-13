#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
    int **DP_tab;
    int numRow;
    int numCol;

public:
    int sumASCII(string& s) {
        int ret = 0;
        for (int i = 0; i < s.size(); ++i) {
            ret+=s[i];
        }
        return ret;
    }

    void printMat() {
        for (int i = 0 ; i < numRow;++i) {
            for (int j = 0; j < numCol; ++j) {
                printf("%d ", DP_tab[i][j]);
            }
            printf("\n");
        }
    }

    int minimumDeleteSum(string s1, string s2) {
        int length1 = s1.size();
        int length2 = s2.size();

        numRow = length1;
        numCol = length2;

        if (length1==0 && length2==0) {
            return 0;
        }

        if (length1==0) {
            return sumASCII(s2);
        } else if (length2 == 0) {
            return sumASCII(s1);
        }

        DP_tab = (int **)malloc(sizeof(int*) * (numRow));
        for (int i = 0; i < numRow; ++i) {
            DP_tab[i] = (int *)calloc(numCol, sizeof(int));
        }

        string tmp;
        for (int i = numRow-1; i>=0; --i) {
            for (int j = numCol-1; j>=0; --j) {
                if (i==numRow-1) {
                    if (j==numCol-1) {
                        if (s1[i]==s2[j]) {
                            DP_tab[i][j]=0;
                            continue;
                        } else {
                            DP_tab[i][j] = (int)s1[i]+(int)s2[j];
                            continue;
                        }
                    } else {
                        if (s1[i]==s2[j]) {
                            tmp = s2.substr(j, numCol-j);
                            DP_tab[i][j] = sumASCII(tmp) - (int)s1[i];
                            continue;
                        }else {
                            DP_tab[i][j] = (int)s2[j] + DP_tab[i][j+1];
                            continue;
                        }
                    }
                }
                if (j==numCol-1) {
                    if (i!=numRow-1) {
                        if (s1[i]==s2[j]) {
                            tmp = s1.substr(i, numRow-i);
                            DP_tab[i][j] = sumASCII(tmp) - (int)s1[i];
                            continue;
                        } else {
                            DP_tab[i][j] = (int)s1[i]+DP_tab[i+1][j];
                            continue;
                        }
                    }
                }

                if (s1[i]==s2[j]) {
                    DP_tab[i][j] = DP_tab[i+1][j+1];
                    continue;
                } else {
                    DP_tab[i][j] = min((int)s2[j]+DP_tab[i][j+1],(int)s1[i]+DP_tab[i+1][j]);
                    continue;
                }
            }
        }

        // printMat();

        return DP_tab[0][0];
    }
};

int main() {
    Solution s = Solution();
    cout<<s.minimumDeleteSum("ppopp", "opp")<<endl;
    cout<<s.minimumDeleteSum("opp", "ppopp")<<endl;
    cout<<s.minimumDeleteSum("sea", "eat")<<endl;
    cout<<s.minimumDeleteSum("delete", "leet")<<endl;
    return 0;
}