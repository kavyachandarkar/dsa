class Solution {
public:
    void dfs(int r,int c,vector<vector<int>>&vis,vector<vector<char>>&mat,vector<int>&drow,vector<int>&dcol){
        vis[r][c]=1;
        int n = mat.size();
        int m = mat[0].size();
        for(int i=0;i<4;i++){
            int nrow = r+drow[i];
            int ncol = c+dcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && mat[nrow][ncol]=='O'){
                dfs(nrow,ncol,vis,mat,drow,dcol);
            }
        }
    }
    void solve(vector<vector<char>>& mat) {
        int n = mat.size();
        int m =mat[0].size();
        vector<int>drow = {-1,0,1,0};
        vector<int>dcol = {0,1,0,-1};
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i =0;i<m;i++){
            if(vis[0][i]==0 && mat[0][i]=='O')dfs(0,i,vis,mat,drow,dcol);
            if(vis[n-1][i]==0 && mat[n-1][i]=='O')dfs(n-1,i,vis,mat,drow,dcol);
        }
        for(int  i=0;i<n;i++){
            if(vis[i][0]==0 && mat[i][0]=='O')dfs(i,0,vis,mat,drow,dcol);
            if(vis[i][m-1]==0 && mat[i][m-1]=='O')dfs(i,m-1,vis,mat,drow,dcol);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && mat[i][j]=='O')mat[i][j]='X';
            }
        }
    }
};