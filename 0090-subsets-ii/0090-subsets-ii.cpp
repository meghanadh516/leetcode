class Solution {
public:

    void backtrack(vector<int>& nums,
                   int start,
                   vector<int>& current,
                   vector<vector<int>>& result) {

        // Every current combination is a valid subset
        result.push_back(current);

        for (int i = start; i < nums.size(); i++) {

            // Skip duplicate elements at the same level
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }

            // Choose
            current.push_back(nums[i]);

            // Explore
            backtrack(nums, i + 1, current, result);

            // Undo
            current.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        vector<vector<int>> result;
        vector<int> current;

        // Important: sort first
        sort(nums.begin(), nums.end());

        backtrack(nums, 0, current, result);

        return result;
    }
};