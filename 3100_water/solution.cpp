// You are given two integers numBottles and numExchange.

// numBottles represents the number of full water bottles that you initially have. In one operation, you can perform one of the following operations:

// Drink any number of full water bottles turning them into empty bottles.
// Exchange numExchange empty bottles with one full water bottle. Then, increase numExchange by one.
// Note that you cannot exchange multiple batches of empty bottles for the same value of numExchange. For example, if numBottles == 3 and numExchange == 1, you cannot exchange 3 empty water bottles for 3 full bottles.

// Return the maximum number of water bottles you can drink.

#include <iostream>

class Solution {
public:
    // taking the number of empty water bottle and the numExchange
    // return the number of full water bottles
    int emptyToFull(int numEmpty, int& numExchange, int& leftEmpty) {
        int ret = 0;
        while(numEmpty>=numExchange) {
            ret++;
            numEmpty-=numExchange;
            numExchange++;            
        }
        leftEmpty = numEmpty;
        // printf("%d empty bottles left\n", leftEmpty);
        return ret;
    }

    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ret = numBottles;
        int empty = numBottles;
        int leftEmpty;
        while (int full = emptyToFull(empty, numExchange, leftEmpty)) {
            ret += full;
            empty = leftEmpty + full;
            // printf("numExchange = %d\n", numExchange);
        }
        return ret;
    }
};

int main() {
    Solution s = Solution();
    // int ret = s.maxBottlesDrunk(10,3);
    int ret = s.maxBottlesDrunk(13,6);
    std::cout << "Ret = " << ret << std::endl;
}