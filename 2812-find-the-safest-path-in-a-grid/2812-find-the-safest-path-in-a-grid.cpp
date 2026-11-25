class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return 0;

        vector<vector<int>> dist(n, vector<int>(n, -1));
        queue<pair<int, int>> q;

        // 1. Initialize Multi-Source BFS with all thief positions
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 1) {
                    dist[r][c] = 0;
                    q.push({r, c});
                }
            }
        }

        int dirs[5] = {-1, 0, 1, 0, -1};

        // 2. Compute minimum Manhattan distance from each cell to any thief
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int i = 0; i < 4; ++i) {
                int nr = r + dirs[i];
                int nc = c + dirs[i + 1];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        // 3. Modified Dijkstra (Max-Heap) to maximize the minimum safeness factor
        priority_queue<tuple<int, int, int>> pq;
        pq.push({dist[0][0], 0, 0});
        dist[0][0] = -1; // Mark (0, 0) as visited in-place

        while (!pq.empty()) {
            auto [safe, r, c] = pq.top();
            pq.pop();

            if (r == n - 1 && c == n - 1) return safe;

            for (int i = 0; i < 4; ++i) {
                int nr = r + dirs[i];
                int nc = c + dirs[i + 1];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && dist[nr][nc] != -1) {
                    int nextSafe = min(safe, dist[nr][nc]);
                    pq.push({nextSafe, nr, nc});
                    dist[nr][nc] = -1; // Mark visited to avoid duplicate pushes
                }
            }
        }

        return 0;
    }
};