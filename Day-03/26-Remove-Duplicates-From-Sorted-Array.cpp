# LeetCode#26 — Remove Duplicates from Sorted Array

**Day:** 03/100  
**Challenge:** #DrGVishwanathanChallenge  
**Difficulty:** Easy  
**Topic:** Array  
**Pattern:** Two Pointers  
**Language:** C++

## Problem Statement

Given an integer array `nums` sorted in non-decreasing order, remove the duplicates in-place so that each unique element appears only once.

The relative order of the unique elements must remain the same. Return the number of unique elements, `k`.

The first `k` elements of `nums` must contain the unique elements in sorted order. The elements beyond index `k - 1` can be ignored.

The operation must be performed **in-place**, using O(1) auxiliary space.



## Example 1

**Input:**
```text
nums = [1,1,2]
```

**Output:**
```text
2, nums = [1,2,_]
```

**Explanation:** There are two unique elements, `1` and `2`. The function returns `k = 2`, and the first two elements become `[1,2]`. The remaining element is ignored.

## Example 2

**Input:**
```text
nums = [0,0,1,1,1,2,2,3,3,4]
```

**Output:**
```text
5, nums = [0,1,2,3,4,_,_,_,_,_]
```

**Explanation:** The unique elements are `[0,1,2,3,4]`. The function returns `k = 5`, and only the first five elements are considered valid.

  

## Approach 1: Brute Force

### Idea

1. Create a temporary array.
2. Traverse the sorted array.
3. Add an element to the temporary array only if it differs from the last stored element.
4. Copy the unique elements back into `nums`.
5. Return the number of unique elements.

Since the array is sorted, duplicate elements appear next to each other.


### C++ Code

```cpp
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> temp;

        for (int num : nums) {
            if (temp.empty() || temp.back() != num) {
                temp.push_back(num);
            }
        }

        for (int i = 0; i < temp.size(); i++) {
            nums[i] = temp[i];
        }

        return temp.size();
    }
};
```


### Complexity Analysis

- **Time Complexity:** O(n), because the array is traversed a constant number of times.
- **Auxiliary Space:** O(n), because a temporary array stores the unique elements.

  

## Approach 2: Optimized — Two Pointers

### Core Concept

The two-pointer technique allows us to remove duplicates logically by overwriting elements in the original array, without creating another array.

We use two variables:

- `i`: Traverses the array to examine each element.
- `k`: Tracks the number of unique elements and the position where the next unique element should be written.

Because the array is sorted, equal elements are adjacent.

Whenever `nums[i] != nums[k - 1]`, we have found a new unique element. Place it at `nums[k]` and increment `k`.
  

### Algorithm

1. If the array is empty, return `0`.
2. Initialize `k = 1`, because the first element is unique when the array is non-empty.
3. Traverse the array from index `1` to `n - 1` using `i`.
4. If `nums[i] != nums[k - 1]`:
   - Assign `nums[k] = nums[i]`.
   - Increment `k`.
5. Return `k`.

  
### Optimized C++ Code

```cpp
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int k = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[k - 1]) {
                nums[k] = nums[i];
                k++;
            }
        }

        return k;
    }
};
```


### Dry Run

**Input:** `nums = [1,1,2,2,3]`

| `i` | `nums[i]` | Comparison | Action | First `k` elements |
|---:|---:|---|---|---|
| — | — | — | Initialize `k = 1` | `[1]` |
| 1 | 1 | `1 == nums[0]` | Skip duplicate | `[1]` |
| 2 | 2 | `2 != nums[0]` | Write `nums[1] = 2`, increment `k` | `[1,2]` |
| 3 | 2 | `2 == nums[1]` | Skip duplicate | `[1,2]` |
| 4 | 3 | `3 != nums[1]` | Write `nums[2] = 3`, increment `k` | `[1,2,3]` |

**Final Result:**

```text
k = 3
First k elements = [1,2,3]
```

The underlying array may be `[1,2,3,2,3]`. This is valid because only the first `k = 3` elements matter.

  

### Complexity Analysis

- **Time Complexity:** O(n), because the array is traversed once.
- **Auxiliary Space:** O(1), because only a constant number of variables are used.
  

## Why Does This Work?

Since the array is sorted, all duplicate occurrences of a value are adjacent. Therefore, comparing the current element with the last unique element is enough to determine whether it is new.

The variable `k` always points to the next position available for a unique element. When a new value is found, it is written to that position, and `k` is incremented.

This maintains the unique elements in sorted order without needing to insert or physically delete elements.
  

## Key Learnings

- Practiced the two-pointer technique.
- Learned to remove duplicates by overwriting elements in-place.
- Understood why sorted arrays make duplicate detection easier.
- Learned the difference between the logical array length `k` and the vector's actual size.
- Practiced returning the number of unique elements.
- Compared brute-force and optimized approaches.
  

## Pattern Recognition

Consider using this two-pointer approach when a problem asks you to:

- Remove duplicates from a sorted array.
- Modify an array in-place.
- Preserve the relative order of valid elements.
- Overwrite unwanted elements without using extra storage.
- Return the count of valid elements after modification.
  

## Edge Cases

- Empty array: `[]` → return `0`.
- Single element: `[5]` → return `1`.
- All elements are identical: `[2,2,2]` → return `1`.
- No duplicates: `[1,2,3]` → return `3`.
- Negative values: `[-3,-3,-1,0,0,2]` → first unique elements become `[-3,-1,0,2]`, return `4`.
  

## Conclusion

This problem demonstrates how the two-pointer technique can remove duplicates efficiently from a sorted array. The optimized approach runs in O(n) time and uses O(1) auxiliary space.

**Day 03/100 — Problem 2 completed!** 🚀
