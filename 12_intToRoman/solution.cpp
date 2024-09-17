#include <string>
#include <map>
#include <iostream>
#include <math.h>


using namespace std;


class Solution {
    public:

    map<int, string> int1Rom;
    map<int, string> int4Rom;
    map<int, string> int5Rom;
    map<int, string> int9Rom;

    Solution () {
        int1Rom[1] = "I";
        int1Rom[10] = "X";
        int1Rom[100] = "C";
        int1Rom[1000] = "M";
        int5Rom[5] = "V";
        int5Rom[50] = "L";
        int5Rom[500] = "D";
        int4Rom[4] = "IV";
        int4Rom[40] = "XL";
        int4Rom[400] = "CD";
        int9Rom[9] = "IX";
        int9Rom[90] = "XC";
        int9Rom[900] = "CM";
    }

    string intToRoman(int num) {
        string ret = "";
        string strNum = to_string(num);
        // printf("%s\n", strNum.c_str());
        // printf("first character is %c\n", strNum[0]);
        int length = strNum.length() - 1;
        int maxSub = 0;

        if (num < 1)
            return "";

        if ((strNum[0] != '4') && (strNum[0] != '9')) {
            if (strNum[0] < '4') {
                maxSub = int(pow(10, length));
                ret.append(int1Rom[maxSub]);
            } else {
                maxSub = int(5*pow(10,length));
                ret.append(int5Rom[maxSub]);
            }
            num -= maxSub;
            ret.append(intToRoman(num));
        } else {
            if (strNum[0] == '4') {
                maxSub = int(4*pow(10, length));
                ret.append(int4Rom[maxSub]);
            } else if (strNum[0] == '9') {
                maxSub = int(9*pow(10, length));
                ret.append(int9Rom[maxSub]);
            }
            num -= maxSub;
            ret.append(intToRoman(num));
        }
        return ret;
    }
};

int main() {
    Solution s = Solution();
    // cout << s.intToRoman(51) << endl;
    cout << s.intToRoman(3749) << endl;
    return 0;
}