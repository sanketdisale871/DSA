class Solution {
public:
    void backtrack(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& visited, int& maxGold, int currentGold) {
        // Check if the current position is within the grid bounds
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) {
            return;
        }

        // Check if the current position has already been visited or has no gold
        if (visited[i][j] || grid[i][j] == 0) {
            return;
        }

        // Update the maximum gold collected
        maxGold = max(maxGold, currentGold + grid[i][j]);

        // Mark the current position as visited
        visited[i][j] = true;

        // Explore the neighboring cells
        backtrack(i - 1, j, grid, visited, maxGold, currentGold + grid[i][j]); // Up
        backtrack(i + 1, j, grid, visited, maxGold, currentGold + grid[i][j]); // Down
        backtrack(i, j - 1, grid, visited, maxGold, currentGold + grid[i][j]); // Left
        backtrack(i, j + 1, grid, visited, maxGold, currentGold + grid[i][j]); // Right

        // Mark the current position as unvisited (backtracking step)
        visited[i][j] = false;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int maxGold = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0) {
                    backtrack(i, j, grid, visited, maxGold, 0);
                }
            }
        }

        return maxGold;
    }
};