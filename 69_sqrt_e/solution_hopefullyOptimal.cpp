#include <stdio.h>
#include <map>
#include <vector>

class Solution {
public:
    int mySqrt(int x) {
        if (x==0)
            return 0;
        if (x<4)
            return 1;
        if (x==4)
            return 2;

        int upperbound = (1<<16);

        int prevBound=x, curBound;
        int result;
        int value = x;
        while(1) {
            value /= 2;
            long long mult = (long long) value * value;
            if (mult == x) 
                return value; 
            else if (mult > x) {
                prevBound = value;
                continue;
            } else if (mult < x) {
                curBound = value;
                break;
            }
        }

        // printf("curBound = %d, prevBound = %d\n", curBound, prevBound);
        for (int i = curBound; i < prevBound; ++i) {
            long long tmp = (long long)i*i;
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
    // printf("S(1) = %d\n", S.mySqrt(1));
    // printf("S(50) = %d\n", S.mySqrt(50));
    printf("S(101010) = %d\n", S.mySqrt(101010));
    printf("S(2147395600) = %d\n", S.mySqrt(2147395600));
    return 0;
}