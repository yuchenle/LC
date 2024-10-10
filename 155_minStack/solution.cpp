#include <iostream>
#include <vector>

using namespace std;

class MinStack {
    vector<int> cheat;
public:
    MinStack() : cheat(vector<int>()) {
    }
    
    void push(int val) {
        cheat.push_back(val);
    }
    
    void pop() {
        cheat.pop_back();
    }
    
    int top() {
        return cheat.back();
    }
    
    int getMin() {
        return *std::min_element(cheat.begin(), cheat.end());
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