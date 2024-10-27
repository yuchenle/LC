#include <vector>
#include <map>

using namespace std;

class Solution {
public:

    vector<int> beautifulArray(int n) {
        unordered_map<int, vector<int>> ensemble;
        ensemble[1] = {1};
        std::function<vector<int>(int)> f;
        f = [&ensemble, &f](int N) -> std::vector<int> {
            printf("f called with %d\n", N);
            if (ensemble.find(N)==ensemble.end()) {
                vector<int> odds = f((N+1)/2);
                vector<int> evens = f(N/2);
                vector<int> res;
                for (int i = 0; i < odds.size(); ++i) {
                    res.push_back(2*odds[i]-1);
                }
                for (int i = 0; i < evens.size(); ++i) {
                    res.push_back(2*evens[i]);
                }
                ensemble[N] = res;
            }
            return ensemble[N];
        };
        return f(n);
    }
};

int main () {
    Solution s = Solution();
    vector<int> res = s.beautifulArray(100);
    for (auto i : res) {
        printf(" %d ", i);
    }
    printf("\n");
    return 0;
}