class Solution {
   public:
    int n, m;

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    void bfs(vector<vector<int>>& grid, queue<pair<int, int>>& q, int& fresh, int r, int c) {
        int size = q.size();
        while (size--) {
            int x = q.front().first;
            int y = q.front().second;

            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;
                    fresh--;
                    q.push({nx, ny});
                }
            }
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        queue<pair<int, int>> q;  // pos of rotten;
        int fresh = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        if (fresh == 0) return 0;

        int time = -1;  // because {0,0} can be rotten

        while (!q.empty()) {
            time++;
            bfs(grid, q, fresh, m, n);
        }

        return (fresh > 0) ? -1 : time;
    }
};
