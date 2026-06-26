class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        ans.insert(ans.end(), nums1.begin(), nums1.end());
        ans.insert(ans.end(), nums2.begin(), nums2.end());
        sort(ans.begin(), ans.end());
        int a = ans.size();
        if (a % 2==1)
            return ans[a / 2];
        else
            return (ans[a/2 - 1] + ans[a/2]) / 2.0;
    }
};
