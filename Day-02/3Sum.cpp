LeetCode 15 — 3Sum


Difficulty: Medium
Language: C++
Topics: Array, Sorting, Two Pointers

Approach: Sorting + Two Pointers

Sort the array in ascending order.
Fix the first element using index i.
Use two pointers, left and right, to find two numbers whose sum equals -nums[i].
If the sum is zero, store the triplet and move both pointers.
Skip duplicate values to ensure that the result contains only unique triplets.
If the sum is less than zero, move left forward. If it is greater than zero, move right backward.



C++ Solution:
  
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();

        // Step 1: Sort the array
        sort(nums.begin(), nums.end());

        // Step 2: Fix the first element
        for (int i = 0; i < n - 2; i++) {

            // Skip duplicate first elements
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            // All remaining values are positive
            if (nums[i] > 0) {
                break;
            }

            int left = i + 1;
            int right = n - 1;

            // Step 3: Find the other two elements
            while (left < right) {
                long long sum = 1LL * nums[i]
                              + nums[left]
                              + nums[right];

                if (sum == 0) {
                    ans.push_back({
                        nums[i], nums[left], nums[right]
                    });

                    left++;
                    right--;

                    // Skip duplicate left values
                    while (left < right &&
                           nums[left] == nums[left - 1]) {
                        left++;
                    }

                    // Skip duplicate right values
                    while (left < right &&
                           nums[right] == nums[right + 1]) {
                        right--;
                    }
                }
                else if (sum < 0) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }

        return ans;
    }
};





Complexity Analysis:

Time Complexity: O(n²) — sorting takes O(n log n), followed by the outer loop and two-pointer search.

Auxiliary Space: Typically O(log n) for the sorting implementation's stack, excluding the output.

Output Space: Depends on the number of unique triplets.





Example:

Input:

nums = [-1, 0, 1, 2, -1, -4]

Output:

[[-1, -1, 2], [-1, 0, 1]]

  

Key Learnings:

Sorting helps make two-pointer searching possible.

Duplicate handling is essential for unique triplets.

The two-pointer technique reduces the brute-force time complexity from O(n³) to O(n²).

Always analyse time and space complexity after solving a problem.
