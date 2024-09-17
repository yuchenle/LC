#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    char **mapString;
    int numR, numC;

    string matToStr() {
        string str = "";
            for (int i = 0; i < numR; ++i) {
                for (int j = 0; j < numC; ++j) {
                    if (mapString[i][j])
                        str.push_back(mapString[i][j]);
                }
        }
        return str;
    }

    string convert(string s, int numRows) {

        if (numRows == 1)
            return s;

        int length = s.length();
        // length / numrRows + 1 is the minimal number of columns needed, all of them being full columns
        // numRows - 2 is how many columns with 1 element between 2 full columns.
        // There are (length/numRows + 1) full columns, so (length/numRows+1) - 1 => length/numRows space. I leave + 1 because I wanted.
        // The summation gives the number of columns needed to store all data.
        int numColumns = (length / numRows + 1) + (length / numRows + 1) * (numRows - 2);
        // cout << numColumns << endl;
        this->numR = numRows;
        this->numC = numColumns;
        mapString = (char **)malloc(sizeof(char *) * numRows);

        for (int i = 0; i < numRows; ++i) {
            mapString[i] = (char *) malloc(sizeof(char) * numColumns);
            memset(mapString[i], 0, sizeof(char) * numColumns);
        }

        printf("number of rows %d, numColumns %d, length is %d\n", numRows, numColumns, length);

        int s_idx = 0;
        for (int i = 0; i < numColumns; ++i) {
            if (s_idx >= length) 
                break;
            if (i%(numRows-1)==0) {
                for (int j = 0; j < numRows; ++j) {
                    // printf("s_idx = %d, %c, [%d, %d] \n", s_idx, s[s_idx], j,i);
                    mapString[j][i] = s[s_idx++];
                    if(s_idx >= length)
                        break;
                }
            } else {
                // printf("s_idx = %d, %c, [%d, %d]\n", s_idx, s[s_idx], numRows - 1 - (i % (numRows - 1)), i);
                mapString[numRows - 1 - (i % (numRows - 1))][i] = s[s_idx++];
                if(s_idx >= length)
                    break;
            }
        }
        return matToStr();
    }

    void printMat() {
        for (int i = 0; i < numR; ++i) {
            for (int j = 0; j < numC; ++j) {
                std::cout << mapString[i][j];
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    Solution *s = new Solution();
    // s->convert("Synopsys", 4);
    // printf("%s\n", s->convert("A", 1).c_str());
    // printf("%s\n", s->convert("Synopsis", 4).c_str());
    printf("%s\n", s->convert("Apalindromeisaword,phrase,number,orothersequenceofunitsthatcanbereadthesamewayineitherdirection,withgeneralallowancesforadjustmentstopunctuationandworddividers.", 3).c_str());
    // s->printMat();
    delete s;
    return 0;
}