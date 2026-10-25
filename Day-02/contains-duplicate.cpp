LeetCode#217 — Contains Duplicate


Difficulty: Easy
Language: C++
Topics: Array, Sorting

Approach: Sorting + Adjacent Comparison

Sort the array in ascending order.
Iterate through the array starting from index 1.
Compare each element with the previous element.
If two adjacent elements are equal, a duplicate exists, so return true.
If no duplicates are found, return false.




C++ Solution:

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // Step 1: Sort the array
        sort(nums.begin(), nums.end());

        // Step 2: Check adjacent elements
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                return true;
            }
        }

        // No duplicate found
        return false;
    }
};




Complexity Analysis:

Time Complexity: O(n log n) — sorting dominates the overall time complexity.

Auxiliary Space: Typically O(log n) for the sorting implementation's stack.

Input Modification: Sorting changes the original array's order.

  

Examples:

Example 1

Input:

[1, 2, 3, 1]

Output:

true

Explanation: The number 1 appears twice.

  

Example 2

Input:

[1, 2, 3, 4]

Output:

false

Explanation: Every element is distinct.

  

Example 3

Input:

[1, 1, 1, 3, 3, 4, 3, 2, 4, 2]

Output:

true

Explanation: Several values occur more than once.

  

Key Learnings:

Sorting places duplicate values next to each other.

Adjacent comparisons make duplicate detection simple.

Sorting provides an O(n log n) solution.

An alternative approach uses unordered_set for expected O(n) time and O(n) extra space.

The best approach depends on the time and space requirements of the problem.
