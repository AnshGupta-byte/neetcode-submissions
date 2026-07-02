class Solution {
   public:
    vector<int> dp;

    int solve(vector<int>& nums, int l, int i) {
        if (i < l) return 0;
        if (dp[i] != -1) return dp[i];

        int take = nums[i] + solve(nums, l, i - 2);
        int nottake = solve(nums, l, i - 1);

        dp[i] = max(take, nottake);
        return dp[i];
    }

    int range(vector<int>& nums, int l, int r) {
        int n = nums.size();
        dp.assign(n, -1);
        return solve(nums, l, r);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }

        int case1 = range(nums, 0, n - 2);
        int case2 = range(nums, 1, n - 1);

        return max(case1, case2);
    }
};
