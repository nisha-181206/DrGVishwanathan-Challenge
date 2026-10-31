class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {

        // Check if the array is empty
        if (nums.empty()) {
            return {};
        }

        for (int i = 1; i < nums.size(); i++) {
            nums[i] += nums[i - 1];
        }

        return nums;
    }
};
