class Solution {
   public:
    int n, m;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    int dfs(int r, int c, vector<vector<int>>& grid) {
        grid[r][c] = 0;
        int area = 1;
        for (int i = 0; i < 4; i++) {
            int nr = r + dx[i];
            int nc = c + dy[i];

            if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                area += dfs(nr, nc, grid);
            }
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0) {
                    ans = max(ans, dfs(i, j, grid));
                }
            }
        }
        return ans;
    }
};
