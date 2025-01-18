class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int m = grid.size(), n = grid[0].size();
        using ti = tuple<int, int, int>;
        priority_queue<ti, vector<ti>, greater<>> pq;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        pq.emplace(0, 0, 0);
        while (pq.size()) {
            auto [cost, x, y] = pq.top(); pq.pop();
            if (vis[x][y]) continue;
            vis[x][y] = 1;
            if (x == m - 1 && y == n - 1) return cost;
            for (int i = 0; i < 4; ++i) {
                auto &[dx, dy] = dir[i];
                int nx = dx + x, ny = dy + y;
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !vis[nx][ny]) {
                    if (i == grid[x][y] - 1) {
                        pq.emplace(cost, nx, ny);
                    } else {
                        pq.emplace(cost + 1, nx, ny);
                    }
                }
            }
        }
        return -1;
    }
};