#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:

    vector<int> decompose(int n) {
        
        if (n<10)
            return {n};
        vector<int> ret;
        while(n>=10){
            ret.insert(ret.begin(), n%10);
            n = n / 10;
        }
        ret.insert(ret.begin(), n);
        return ret;
    }

    int addDigits(int num) {
        int ret;
        while(1) {
            vector<int> res = decompose(num);
            if (res.size() == 1) {
                ret = res[0];
                break;
            } else {
                int newNum = 0;
                for (auto elem : res) {
                    newNum += elem;
                }
                num = newNum;
            }
        }
        return ret;
    }
};
