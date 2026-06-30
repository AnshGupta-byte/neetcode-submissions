class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> s;
        int ans = 0;

        for (int i = 0; i <= n; i++) {
            int h = (i == n ? 0 : heights[i]);

            while (!s.empty() && heights[s.top()] > h) {
                int height = heights[s.top()];
                s.pop();

                int right = i;
                int left = s.empty() ? -1 : s.top();

                int width = right - left - 1;
                ans = max(ans, height * width);
            }

            s.push(i);
        }

        return ans;
    }
};
