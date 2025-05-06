class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

        vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
        dis[0][0] = 0;

        vector<int> dir_r = {-1, 0, 1, 0};
        vector<int> dir_c = {0, 1, 0, -1};

        pq.push({0, {0, 0}});

        while (!pq.empty()) {
            auto [effort, pos] = pq.top();
            pq.pop();
            int r = pos.first, c = pos.second;

            if (r == n - 1 && c == m - 1) return effort;


            if (effort > dis[r][c]) continue;

            for (int i = 0; i < 4; ++i) {
                int nr = r + dir_r[i];
                int nc = c + dir_c[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    int currentEffort = abs(heights[r][c] - heights[nr][nc]);
                    int newEffort = max(currentEffort, effort);

                    if (newEffort < dis[nr][nc]) {
                        dis[nr][nc] = newEffort;
                        pq.push({newEffort, {nr, nc}});
                    }
                }
            }
        }

        return 0; 
    }
};
