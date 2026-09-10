class Solution {
public:

    void backtrack(int n,
                   int open,
                   int close,
                   string& current,
                   vector<string>& result) {

        // We used all parentheses
        if (current.size() == 2 * n) {
            result.push_back(current);
            return;
        }

        // Add '(' if we still have some left
        if (open < n) {
            current.push_back('(');

            backtrack(n, open + 1, close, current, result);

            current.pop_back();
        }

        // Add ')' only if it is valid
        if (close < open) {
            current.push_back(')');

            backtrack(n, open, close + 1, current, result);

            current.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {

        vector<string> result;
        string current;

        backtrack(n, 0, 0, current, result);

        return result;
    }
};