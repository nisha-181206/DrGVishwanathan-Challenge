class Solution {
public:
    vector<int> intersection(vector<int>& nums1,
                             vector<int>& nums2) {

        // Handle empty arrays
        if (nums1.empty() || nums2.empty()) {
            return {};
        }

        // Store unique elements of nums1
        unordered_set<int> st(nums1.begin(), nums1.end());

        vector<int> ans;

        // Find common elements
        for (int num : nums2) {
            if (st.erase(num)) {
                ans.push_back(num);
            }
        }

        return ans;
    }
};
