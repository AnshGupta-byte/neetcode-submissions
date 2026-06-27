class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int longest = 0;
        for (int x : st) {
            if (st.count(x - 1)) continue;

            int curr = x;
            int count = 1;
            while (st.count(curr + 1)) {
                curr++;
                count++;
            }
            longest = max(longest, count);
        }
        return longest;
    }
};
