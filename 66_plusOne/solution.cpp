class Solution {
public:

    void propagateOne(vector<int>& digits, int pos) {
        int length = digits.size();
        if (pos < length && pos >= 0)
            digits[pos]++;
        if (digits[pos]==10) {
            digits[pos] = 0;
            if (pos==0)
                digits.insert(digits.begin(), 1);
            else
                propagateOne(digits, pos-1);
        }
    }

    vector<int> plusOne(vector<int>& digits) {
        
        int length = digits.size();
        if (digits[length-1] == 9) {
            propagateOne(digits, length-1);
        } else {
            digits[length-1]++;
            return digits;
        }
        return digits;
    }
};