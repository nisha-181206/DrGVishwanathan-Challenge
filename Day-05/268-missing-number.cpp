class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        int n = nums.size();
        int result = n;

        for (int i = 0; i < n; i++) {
            result ^= i ^ nums[i];
        }

        return result;
    }
};
