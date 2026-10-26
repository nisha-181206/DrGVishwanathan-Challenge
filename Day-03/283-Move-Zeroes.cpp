# LeetCode 283 — Move Zeroes

**Day:** 03/100  
**Challenge:** #DrGVishwanathanChallenge  
**Difficulty:** Easy  
**Topic:** Array  
**Pattern:** Two Pointers  
**Language:** C++

  
## Problem Statement

Given an integer array `nums`, move all zeros to the end of the array while maintaining the relative order of all non-zero elements.

The operation must be performed **in-place**, without making a copy of the array.


## Example 1

**Input:**
```text
nums = [0,1,0,3,12]
```

**Output:**
```text
[1,3,12,0,0]
```

**Explanation:** All non-zero elements are moved to the beginning in their original order, and all zeros are placed at the end.

## Example 2

**Input:**
```text
nums = [0]
```

**Output:**
```text
[0]
```

**Explanation:** The array contains only one zero, so no changes are needed.

  

## Approach 1: Brute Force

### Idea

1. Create a temporary array.
2. Store all non-zero elements in it.
3. Copy the non-zero elements back into `nums`.
4. Fill the remaining positions with zeros.
  

### C++ Code

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> temp;

        for (int num : nums) {
            if (num != 0) {
                temp.push_back(num);
            }
        }

        int i = 0;

        for (int num : temp) {
            nums[i++] = num;
        }

        while (i < nums.size()) {
            nums[i++] = 0;
        }
    }
};
```

### Complexity Analysis

- **Time Complexity:** O(n)
- **Auxiliary Space:** O(n), because a temporary array stores the non-zero elements.

  

## Approach 2: Optimized — Two Pointers

### Core Concept

The two-pointer technique allows us to modify the array in-place without creating an additional array.

We use two pointers:

- `right`: Traverses every element of the array.
- `left`: Tracks the position where the next non-zero element should be placed.

Whenever `nums[right] != 0`, swap `nums[left]` and `nums[right]`, then increment `left`.


### Algorithm

1. Initialize `left = 0`.
2. Traverse the array using `right` from index `0` to `n - 1`.
3. If the current element is non-zero:
   - Swap `nums[left]` and `nums[right]`.
   - Increment `left`.
4. Continue until all elements have been processed.


### Optimized C++ Code

```cpp
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0;

        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] != 0) {
                swap(nums[left], nums[right]);
                left++;
            }
        }
    }
};
```


### Dry Run

**Input:** `nums = [0,1,0,3,12]`

| `right` | `nums[right]` | Action | Array |
|---:|---:|---|---|
| 0 | 0 | Skip zero | `[0,1,0,3,12]` |
| 1 | 1 | Swap indices 0 and 1 | `[1,0,0,3,12]` |
| 2 | 0 | Skip zero | `[1,0,0,3,12]` |
| 3 | 3 | Swap indices 1 and 3 | `[1,3,0,0,12]` |
| 4 | 12 | Swap indices 2 and 4 | `[1,3,12,0,0]` |
  

**Final Output:** `[1,3,12,0,0]`

### Complexity Analysis

- **Time Complexity:** O(n), because the array is traversed once.
- **Auxiliary Space:** O(1), because only a constant number of variables are used.

  

## Why Does This Work?

The `left` pointer always indicates the next position for a non-zero element. When a non-zero element is found, placing it at `left` keeps all non-zero elements in their original relative order.

The zero displaced by a swap moves toward the unprocessed or trailing zero positions. After the complete traversal, all non-zero elements appear first, followed by zeros.



## Key Learnings

- Practiced the two-pointer technique.
- Learned how to modify an array in-place.
- Understood how swapping can avoid using an extra array.
- Learned the difference between O(n) auxiliary space and O(1) auxiliary space.
- Practiced preserving the relative order of elements.


## Pattern Recognition

Consider using two pointers when a problem asks you to:

- Move particular elements to one side of an array.
- Modify an array in-place.
- Preserve the relative order of selected elements.
- Avoid creating an additional array.



## Edge Cases

- Empty array: `[]`
- Single zero: `[0]`
- No zeros: `[1,2,3]`
- All zeros: `[0,0,0]`
- Zeros at the beginning or end of the array.


## Conclusion

This problem demonstrates how the two-pointer technique can solve an array modification problem efficiently. The optimized approach runs in O(n) time and uses O(1) auxiliary space.

**Day 03/100 — Problem 1 completed!** 🚀
