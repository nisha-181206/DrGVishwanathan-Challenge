class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if(nums.empty()){
          return 0;
        }
      
        int totalSum = 0;
        int leftSum = 0;

        // Step 1: Calculate the total sum
        for (int num : nums) {
            totalSum += num;
        }

        // Step 2: Find the pivot index
        for (int i = 0; i < nums.size(); i++) {
            int rightSum = totalSum - leftSum - nums[i];

            if (leftSum == rightSum) {
                return i;
            }

            leftSum += nums[i];
        }

        return -1;
    }
};
