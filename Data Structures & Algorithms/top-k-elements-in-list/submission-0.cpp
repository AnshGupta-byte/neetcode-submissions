class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;

        for (int x : nums) mp[x]++;

        vector<vector<int>> buckets(n + 1);
        for (auto const& pair : mp) {
            int num = pair.first;
            int freq = pair.second;
            buckets[freq].push_back(num);
        }

        vector<int> ans;
        for (int i = n; i >= 0; i--) {
            if (buckets[i].size() == 0) continue;
            for (int num : buckets[i]) {
                ans.push_back(num);
                if (ans.size() == k) {
                    return ans;
                }
            }
        }

        return ans;
    }
};
