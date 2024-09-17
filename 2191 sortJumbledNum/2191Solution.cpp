#include <vector>
#include <iostream>
#include <map>
#include <string>
#include <deque>
#include <algorithm>

using namespace std;

class Solution {
public:
    std::vector<int> getDigits(int number) {
        std::vector<int> digits;

        // Special case for zero
        if (number == 0) {
            digits.push_back(0);
            return digits;
        }

        // Ensure the number is positive
        //if (number < 0) {
        //    number = -number;
        //}

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

    long long composeNumber(std::vector<int>& digits) {
        long long number = 0;

        for (int digit : digits) {
            // Validate that each element is a single digit between 0 and 9
            //if (digit < 0 || digit > 9) {
            //    throw std::invalid_argument("All elements must be digits between 0 and 9.");
            //}

            // Update the number by shifting existing digits left and adding the new digit
            number = number * 10 + digit;
        }

        return number;
    }

    map<int , deque<int>> mappingToNum;

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {

        //if (mapping.size() != 10)
        //    return vector<int>();

        //if (nums.size() == 1)
        //    return nums;
        vector<int> arrayToSort;
        vector<int> ret;

        for (int i = 0; i < nums.size(); ++i) {
            vector <int> VecNum = getDigits(nums[i]);
            vector <int> convNum;

            for (int j = 0; j < VecNum.size(); ++j)
                convNum.push_back(mapping[VecNum[j]]);

            int mappedKey = composeNumber(convNum);
            mappingToNum[mappedKey].push_back(nums[i]);
        }

        for (const auto& entry : mappingToNum) {
            arrayToSort.push_back(entry.first);
        }

        std::sort(arrayToSort.begin(), arrayToSort.end());

        //cout << "arrayToSort has " << arrayToSort.size() << " elements" << endl;

        for (auto num : arrayToSort) {
            auto queue = mappingToNum[num];
            //cout << "size of queue is " << queue.size() << endl;
            for (int i = 0; i < queue.size(); ++i) {
                ret.push_back(mappingToNum[num][i]);
                //queue.pop_front();
            }
        }

        return ret;
    }
};