class Solution {
public:
    string decodeCiphertext(string enc, int rows) {
        int n = enc.size();
        if (n == 0) return "";

        int cols = n / rows;
        vector<vector<char>> mat(rows, vector<char>(cols));

        int k = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                mat[i][j] = enc[k++];
            }
        }

        string ans = "";
        for (int start = 0; start < cols; start++) {
            int i = 0, j = start;
            while (i < rows && j < cols) {
                ans += mat[i][j];
                i++;
                j++;
            }
        }

        while (!ans.empty() && ans.back() == ' ') ans.pop_back();
        return ans;
    }
};
