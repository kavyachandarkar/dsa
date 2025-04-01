#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int startColor = image[sr][sc];

        if (startColor == color) return image;

        bfs(color, startColor, sr, sc, image, n, m);
        return image;
    }

private:
    void bfs(int newColor, int startColor, int sr, int sc, vector<vector<int>>& image, int n, int m) {
        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = newColor; 

        vector<int> dRow = {-1, 1, 0, 0};
        vector<int> dCol = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int newRow = row + dRow[i];
                int newCol = col + dCol[i];

                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && image[newRow][newCol] == startColor) {
                    image[newRow][newCol] = newColor;
                    q.push({newRow, newCol});
                }
            }
        }
    }
};
