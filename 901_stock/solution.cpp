#include <vector>
#include <iostream>

class StockSpanner {
public:
    int prices[10000];
    int day;
    StockSpanner() {
        memset(prices, 0, sizeof(int)*10000);
        day=0;
    }
    
    int next(int price) {
        prices[day++]=price;
        int ret = 1;
        for (int i = day-2; i >= 0; --i) {
            if (prices[i] <= price)
                ret++;
            else
                break;
        }
        return ret;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */