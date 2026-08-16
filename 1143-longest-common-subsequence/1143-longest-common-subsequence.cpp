class Solution {
    vector<vector<int>> dp;

public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        dp.assign(n, vector<int>(m, -1));

        return solve(text1, text2, 0, 0);
    }

private:
    int solve(string& text1, string& text2, int i, int j) {

        // Reached the end of either string
        if (i == text1.size() || j == text2.size())
            return 0;

        // Already calculated
        if (dp[i][j] != -1)
            return dp[i][j];

        // Characters match
        if (text1[i] == text2[j]) {
            return dp[i][j] =
                1 + solve(text1, text2, i + 1, j + 1);
        }

        // Characters don't match
        return dp[i][j] = max(
            solve(text1, text2, i + 1, j),
            solve(text1, text2, i, j + 1)
        );
    }
};