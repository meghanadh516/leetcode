class Solution {
public:

    void backtrack(vector<int>& candidates,
                   int target,
                   int start,
                   vector<int>& current,
                   vector<vector<int>>& result) {

        // Target reached
        if (target == 0) {
            result.push_back(current);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {

            // Skip duplicate numbers at the same level
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }

            // If number is bigger than target
            if (candidates[i] > target) {
                break;
            }

            // Choose
            current.push_back(candidates[i]);

            // Explore
            // i + 1 means we cannot reuse this number
            backtrack(candidates,
                      target - candidates[i],
                      i + 1,
                      current,
                      result);

            // Undo
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates,
                                         int target) {

        vector<vector<int>> result;
        vector<int> current;

        // Important: sort first
        sort(candidates.begin(), candidates.end());

        backtrack(candidates, target, 0, current, result);

        return result;
    }
};