class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            
            // Checks if the complement exists (returns 1 if true, 0 if false)
            if (numMap.count(complement)) {
                return {numMap[complement], i};
            }
            
            // Store the current number and its index
            numMap[nums[i]] = i;
        }
        
        return {};
    }
};
