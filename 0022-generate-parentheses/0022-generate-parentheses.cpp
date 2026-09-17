class Solution {
public:
    vector<string> ans;

    void solve(string curr, int open, int close, int n) {

        // Base case:
        // We have used all 2*n parentheses
        if(curr.length() == 2 * n) {
            ans.push_back(curr);
            return;
        }

        // We can add '(' if we still have some left
        if(open < n) {
            curr.push_back('(');

            solve(curr, open + 1, close, n);

            // Backtrack
            curr.pop_back();
        }

        // We can add ')' only if it does not make
        // the parentheses invalid
        if(close < open) {
            curr.push_back(')');

            solve(curr, open, close + 1, n);

            // Backtrack
            curr.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {

        string curr = "";

        solve(curr, 0, 0, n);

        return ans;
    }
};