class Solution {
public:

    void backtrack(string& digits,
                   int index,
                   string& current,
                   vector<string>& result) {

        // We used all digits
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }

        // Phone keypad mapping
        string letters[] = {
            "", "", "abc", "def",
            "ghi", "jkl", "mno",
            "pqrs", "tuv", "wxyz"
        };

        // Get letters for current digit
        string possible = letters[digits[index] - '0'];

        // Try every possible letter
        for (char c : possible) {

            // Choose
            current.push_back(c);

            // Explore next digit
            backtrack(digits, index + 1, current, result);

            // Undo
            current.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        vector<string> result;

        if (digits.empty()) {
            return result;
        }

        string current;

        backtrack(digits, 0, current, result);

        return result;
    }
};