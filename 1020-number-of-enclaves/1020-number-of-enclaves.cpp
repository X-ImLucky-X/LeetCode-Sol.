class Solution {
public:
    vector<vector<int>> dir={
        {1,0},{-1,0},{0,1},{0,-1}
    };
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            if(grid[i][0]==1)dfs(i,0,vis,grid);
            if(grid[i][n-1]==1)dfs(i,n-1,vis,grid);
        }
        for(int i=0;i<n;i++){
            if(grid[0][i]==1)dfs(0,i,vis,grid);
            if(grid[m-1][i]==1)dfs(m-1,i,vis,grid);
        }

        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)count++;
            }
        }
        return count;
    }
private:
    void dfs(int r,int c,vector<vector<bool>>& vis,vector<vector<int>>& grid){
        if(grid[r][c]==1 && !vis[r][c]){
            grid[r][c]=0;
            vis[r][c]=true;
        }
        for(auto x:dir){
            int nr=r+x[0];
            int nc=c+x[1];
            if(nr>=0 && nc>=0 && nr<grid.size() && nc<grid[0].size() && grid[nr][nc]==1){
                dfs(nr,nc,vis,grid);
            }
        }
    }
};