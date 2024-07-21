#include <stdio.h>

class Solution {
public:
    int mySqrt(int x) {
        if (x<4)
            return 1;
        if (x<9)
            return 2;
        int upperbound = (1<<16);
            

        /*
        int count = 2;
        while (count < upperbound) {
            int count2 = count * count;
            if (count2 == x)
            return count;
            else if (count2 < x)
        }
        */

        int result;
        for (int i = 2; i < upperbound; ++i) {
            long long tmp = (long long)i*i;
            printf("tmp = %lld, i = %d\n", tmp, i);
            if (tmp <= x)
              result = i;
            else
              return result;
        }
        return result;
    }
};

int main() {
    Solution S;
    printf("S(1) = %d\n", S.mySqrt(1));
    printf("S(50) = %d\n", S.mySqrt(50));
    printf("S(101010) = %d\n", S.mySqrt(101010));
    printf("S(2147395600) = %d\n", S.mySqrt(2147395600));
    return 0;
}