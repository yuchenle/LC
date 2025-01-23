#include <vector>
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:

    vector<int> partitionInt(int num) {
        vector<int> ret;
        do {
            ret.push_back(num%10);
            num /= 10;
        }while(num>=1);
        // for(auto ii : ret) {
        //     printf("%d ", ii);
        // }
        // printf("\n");
        return ret;
    }

    int punishmentNumber(int n) {
        int ret=0;
        for (int i = 1; i <= n; ++i) {
            int sqred = i*i;
            vector<int> arr = partitionInt(sqred);
            int summ = 0;
            for (auto eachElem : arr) {
                summ += eachElem;
            }
            if (summ==i) {
                printf("summ=%d\n",summ);
                ret+=sqred;
            }
        }
        return ret;
    }
};

int main() {
    Solution s = Solution();
    s.partitionInt(2);
    cout<<s.punishmentNumber(10)<<endl;
    cout<<s.punishmentNumber(37)<<endl;
    // s.partitionInt(99);
    return 0;
}
