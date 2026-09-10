class Solution {
public:

    void backtrack(vector<int>& nums,
                   vector<bool>& used,
                   vector<int>& current,
                   vector<vector<int>>& result) {

        // If current permutation contains all numbers
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }

        // Try every number
        for (int i = 0; i < nums.size(); i++) {

            // Skip if already used
            if (used[i]) {
                continue;
            }

            // Choose
            used[i] = true;
            current.push_back(nums[i]);

            // Explore
            backtrack(nums, used, current, result);

            // Undo
            current.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> result;
        vector<int> current;
        vector<bool> used(nums.size(), false);

        backtrack(nums, used, current, result);

        return result;
    }
};