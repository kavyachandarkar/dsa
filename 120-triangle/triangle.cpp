class Solution {
public:
    int h(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& tri) {
        int n = tri.size();
        if (i == n - 1) return tri[i][j];  

        if (dp[i][j] != -1) return dp[i][j];

        int down = h(i + 1, j, dp, tri);
        int diag = h(i + 1, j + 1, dp, tri);

        return dp[i][j] = tri[i][j] + min(down, diag);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));  
        return h(0, 0, dp, triangle);  
    }
};
