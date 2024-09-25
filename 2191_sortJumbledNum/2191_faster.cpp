#include <vector>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

class Solution {
public:

    vector<pair<int,int>> mappedVar;

    vector<int> getDigits(int number) {
        std::vector<int> digits;

        // Special case for zero
        if (number == 0) {
            digits.push_back(0);
            return digits;
        }

        // Find the highest divisor
        int divisor = 1;
        while (number / divisor >= 10) {
            divisor *= 10;
        }

        // Extract digits
        while (divisor > 0) {
            int digit = number / divisor;
            digits.push_back(digit);
            number %= divisor;
            divisor /= 10;
        }

        return digits;
    }

    long long composeNumber(vector<int>& digits) {
        long long number = 0;

        for (int digit : digits) {
            // Update the number by shifting existing digits left and adding the new digit
            number = number * 10 + digit;
        }
        return number;
    }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {

        mappedVar.reserve(nums.size());

        if (mapping.size() != 10)
           return vector<int>();

        if (nums.size() == 1)
           return nums;

        vector<int> ret;

        for (int i = 0; i < nums.size(); ++i) {
            int mappedKey;
            string strNum = std::to_string(nums[i]);
            string mappedNum = "";

            for (int j = 0; j < strNum.size(); ++j)
                mappedNum += char(48 + mapping[strNum[j] - 48]); //48 because ascii(0) = 48

            mappedKey = std::stoi(mappedNum);
            mappedVar.push_back(pair(mappedKey, i));
        }

        std::sort(mappedVar.begin(), mappedVar.end());

        for (auto onePair : mappedVar) {
            ret.push_back(nums[onePair.second]);
        }

        return ret;
    }
};