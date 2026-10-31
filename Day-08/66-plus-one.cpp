class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // Check if the array is empty
        if (digits.empty()) {
            return {};
        }

        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }

            digits[i] = 0;
        }

        digits.insert(digits.begin(), 1);
        return digits;
    }
};
