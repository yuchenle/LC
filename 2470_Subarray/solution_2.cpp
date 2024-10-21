#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    int subarrayLCM(std::vector<int>& nums, int k) {
        int count = 0;
        std::unordered_map<int, int> prev_lcms;

        for (int num : nums) {
            std::unordered_map<int, int> curr_lcms;

            if (num == 0) continue; // Skip zero to avoid division by zero

            int lcm = num;
            if (k % lcm == 0) {
                curr_lcms[lcm] += 1;
                if (lcm == k) {
                    count += 1;
                }
            }

            for (const auto& [prev_lcm, freq] : prev_lcms) {
                int new_lcm = lcmOfTwoNumbers(prev_lcm, num);
                if (new_lcm > k || k % new_lcm != 0) continue;
                curr_lcms[new_lcm] += freq;
                if (new_lcm == k) {
                    count += freq;
                }
            }

            prev_lcms = std::move(curr_lcms);
        }

        return count;
    }

private:
    int gcdOfTwoNumbers(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    int lcmOfTwoNumbers(int a, int b) {
        return (a / gcdOfTwoNumbers(a, b)) * b;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {3,6,2,7,1};
    int k = 6;
    int result = solution.subarrayLCM(nums, k);
    std::cout << "Number of subarrays with LCM " << k << ": " << result << std::endl;
    return 0;
}
