class Solution {
public:

    void backtrack(int start, int n, int k,
                   vector<int>& current,
                   vector<vector<int>>& result) {

        // If we have selected k numbers
        if (current.size() == k) {
            result.push_back(current);
            return;
        }

        // Try every number from start to n
        for (int i = start; i <= n; i++) {

            // Choose
            current.push_back(i);

            // Explore
            backtrack(i + 1, n, k, current, result);

            // Undo the choice
            current.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {

        vector<vector<int>> result;
        vector<int> current;

        backtrack(1, n, k, current, result);

        return result;
    }
};