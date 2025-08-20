#include <vector>
#include <algorithm> // For std::min

class Solution {
public:
   
    int countSquares(std::vector<std::vector<int>>& matrix) {
       
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }

        int n = matrix.size();
        int m = matrix[0].size();
        
        
        std::vector<std::vector<int>> dp(n, std::vector<int>(m, 0));
        
        
        int totalSquares = 0;

      
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
              
                if (matrix[i][j] == 1) {
                  
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        
                        int minNeighbor = std::min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                        
                        dp[i][j] = 1 + minNeighbor;
                    }
                }
                
                totalSquares += dp[i][j];
            }
        }

        return totalSquares;
    }
};
