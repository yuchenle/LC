/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 */
 class CustomFunction {
 public:
     // Returns f(x, y) for any given positive integers x and y.
     // Note that f(x, y) is increasing with respect to both x and y.
     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
     int f(int x, int y);
 };

#include <cmath>
#include <vector>
#include <set>

using namespace std;


class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>> ret;
        for (int i = 1; i <= 1000; ++i) {
            for (int j = 1; j <= 1000; ++j) {
                int res = customfunction.f(i,j);
                if (res <= z) {
                    if (customfunction.f(i,j)==z) {
                        ret.push_back({i,j});
                    }
                } else {
                    // without this break, the execution time goes from 0 ms to 100ish ms.
                    break;
                }
            }
        }
        return ret;
    }
};