#include <map>
#include <vector>

using namespace std;

class CountIntervals {
private:
    unordered_map<int,int> tracer;
    int cur_min;
    int cur_max;
    int counter;
public:
    CountIntervals() : tracer(unordered_map<int,int>()), cur_min(INT_MAX), cur_max(INT_MIN), counter(0) {}
    
    void add(int left, int right) {
        if (left>cur_max) {
            tracer[left] = right;
            cur_max = right;
            if (left < cur_min)
                cur_min = left;
            printf("case 1, adding %d to counter\n", right - left + 1);
            counter += right - left + 1;
        } else if (right < cur_min) {
            tracer[left] = right;
            cur_min = left;
            if (right > cur_max)
                cur_max = right;
            printf("case 2, adding %d to counter\n", right - left + 1);
            counter += right - left + 1;
        } else {
            int keyToRemove = -1;
            for (auto &elem : tracer) {
                if (left >= elem.first && left <= elem.second) {
                    if (right > elem.second) {
                        printf("case 3, adding %d to counter\n", right - elem.second);
                        counter += right - elem.second;
                        elem.second = right;
                        if (right > cur_max)
                            cur_max = right;
                        continue;
                    }
                } else if (right >= elem.first && right <= elem.second){
                    if (left < elem.first) {
                        printf("case 4, adding %d to counter\n", elem.first - left);
                        counter += elem.first - left;
                        // elem.first = left;
                        keyToRemove = elem.first;
                        tracer[left] = elem.second;
                        if (left < cur_min)
                            cur_min = left;
                        continue;
                    }
                }
            }
            if (keyToRemove != -1)
                tracer.erase(keyToRemove);            
        }
    }
    
    int count() {
        return this->counter;
    }
};

int main() {
    CountIntervals ci = CountIntervals();
    ci.add(39,44);
    ci.add(13,49);
    int num = ci.count();
    printf("num = %d\n", num);
    return 0;
}

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */