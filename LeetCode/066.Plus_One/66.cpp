class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ret;
        int i = digits.size() - 1, carry = 1, t;
        while (i >= 0) {
            t = digits[i] + carry;
            digits[i--] = t % 10;
            carry = t / 10;
        }
        if (carry) ret.push_back(1);
        for (size_t i = 0; i < digits.size(); i++) ret.push_back(digits[i]);
        return ret;
    }
};