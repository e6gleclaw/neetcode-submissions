
class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) return;

        int m = grid[0].size();
        if (m == 0) return;

        const int INF = 2147483647;

        queue<pair<int, int>> q;

        // Step 1: Add every treasure chest to the queue
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        // Down, up, right, left
        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        // Step 2: Run BFS from all treasure chests
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nr = row + dr[k];
                int nc = col + dc[k];

                // Process only unvisited land cells
                if (nr >= 0 && nr < n &&
                    nc >= 0 && nc < m &&
                    grid[nr][nc] == INF) {

                    grid[nr][nc] = grid[row][col] + 1;
                    q.push({nr, nc});
                }
            }
        }
    }
};
