class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        if (grid[0][0] != 0 || grid[n-1][n-1] != 0)
            return -1;

        vector<vector<int>> visited(n, vector<int>(n, 0));
        queue<pair<int, pair<int, int>>> q;

        vector<int> dir_r = {-1, -1, -1, 0, 1, 1, 1, 0};
        vector<int> dir_c = {-1, 0, 1, 1, 1, 0, -1, -1};

        q.push({1, {0, 0}});
        visited[0][0] = 1;

        while (!q.empty()) {
            auto [dist, pos] = q.front(); q.pop();
            int r = pos.first, c = pos.second;

            if (r == n - 1 && c == n - 1)
                return dist;

            for (int i = 0; i < 8; i++) {
                int new_r = r + dir_r[i];
                int new_c = c + dir_c[i];

                if (new_r >= 0 && new_r < n && new_c >= 0 && new_c < n &&
                    grid[new_r][new_c] == 0 && !visited[new_r][new_c]) {
                    
                    visited[new_r][new_c] = 1;
                    q.push({dist + 1, {new_r, new_c}});
                }
            }
        }

        return -1;
    }
};
