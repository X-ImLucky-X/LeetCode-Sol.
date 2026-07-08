class Solution {
public:
    vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            if(board[i][0]=='O' && !vis[i][0])dfs(i,0,board,vis);
            if(board[i][n-1]=='O' && !vis[i][n-1])dfs(i,n-1,board,vis);
        }
        for(int i=0;i<n;i++){
            if(board[0][i]=='O' && !vis[0][i])dfs(0,i,board,vis);
            if(board[m-1][i]=='O' && !vis[m-1][i])dfs(m-1,i,board,vis);
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
private:
    void dfs(int r,int c,vector<vector<char>>& board,vector<vector<bool>>& vis){
        vis[r][c]=true;
        for(auto x:dir){
            int row=r+x[0];
            int col=c+x[1];
            if(row>=0 && col>=0 && row<board.size() && col<board[0].size() && !vis[row][col] && board[row][col]=='O'){
                dfs(row,col,board,vis);
            }
        }
    }
};