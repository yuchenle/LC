#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:

    bool isBalanced(int n) {
        string stringN = std::to_string(n);
        int length = stringN.size();
        int occurences[9] = {0};
        for (int i = 0; i < length; ++i) {
            if (stringN[i]=='0')
                return false;
            else
                occurences[(int)stringN[i] - 49]++;
        }

        for (int i = 0; i < 9; ++i) {
            if (occurences[i]!=0 && occurences[i]!=i+1)
                return false;
        }
        return true;
    }

    int nextBeautifulNumber(int n) {
        if (n==0)
            return 1;
        if (n<22)
            return 22;
        // if n>=22, there must be at least 3 digits in the result.
        int ndigits = 3;
        string stringN = std::to_string(n);
        int length = stringN.size();
        int max_digit = length;
        for (int i = 1; i < length; ++i){
            max_digit *= 10;
            max_digit += length;
        }
        printf("max_digit is %d\n", max_digit);
        if (n >= max_digit)
            max_digit = (int)std::pow(10,length) + max_digit;
        for (int i = n+1; i <= max_digit; ++i) {
            if(isBalanced(i))
                return i;
        }
        return 0;
    }
};

int main() {
    Solution s = Solution();
    // cout<<s.nextBeautifulNumber(23)<<endl;
    // cout<<s.nextBeautifulNumber(334)<<endl;
    cout<<s.nextBeautifulNumber(666666)<<endl;
    return 0;
}