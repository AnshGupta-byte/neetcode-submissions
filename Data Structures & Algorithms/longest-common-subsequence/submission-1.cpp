class Solution {
   public:
    int helper(string& text1, string& text2, int i, int j, vector<vector<int>>& dp) {
        if (i == text1.size() || j == text2.size()) {
            return 0;
        }

        if (dp[i][j] != -1) return dp[i][j];

        int ans;

        if (text1[i] == text2[j]) {
            ans = 1 + helper(text1, text2, i + 1, j + 1, dp);
        } else {
            int option1 = helper(text1, text2, i + 1, j, dp);
            int option2 = helper(text1, text2, i, j + 1, dp);

            ans = max(option1, option2);
        }

        dp[i][j] = ans;
        return dp[i][j];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        int ans = helper(text1, text2, 0, 0, dp);
        return ans;
    }
};
