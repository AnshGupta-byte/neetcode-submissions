class Solution {
   public:
    vector<int> dp;
    int solve(vector<int>& nums, int i) {
        if (i < 0) return 0;
        if (i == 0) return nums[0];
        if (dp[i] != -1) return dp[i];
        int take = nums[i] + solve(nums, i - 2);
        int nottake = solve(nums, i - 1);

        dp[i] = max(take, nottake);
        return dp[i];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n + 1, -1);
        return solve(nums, n - 1);
        /*
          int n = nums.size();
          vector<int> dp(n+2,0);

          for(int i= n-1; i>=0;i--){
              dp[i] = max(nums[i] + dp[i+2] , dp[i+1] );
          }
          return dp[0];
          */
    }
};
