#include <iostream>
#include <vector>

using namespace std;

class MinStack {
    int *stack;
    int *min_dyn;
    int cur_size;
public:
    MinStack() {
        // simply assuming that there are at most 1000 integers.
        stack = (int *)malloc(sizeof(int) * 30000);
        min_dyn = (int *)malloc(sizeof(int) * 30000);
        
        for (int i = 0; i < 30000; ++i)
            min_dyn[i] = INT_MAX;

        cur_size = 0;
    }
    
    void push(int val) {
        stack[cur_size++] = val;
        if (val < min_dyn[cur_size - 1])
            min_dyn[cur_size] = val;
        else
            min_dyn[cur_size] = min_dyn[cur_size-1];
    }
    
    void pop() {
        cur_size--;
    }
    
    int top() {
        return stack[cur_size-1];
    }
    
    int getMin() {
        return min_dyn[cur_size];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */