class Solution {
public:
    vector<vector<int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> ans(m,vector<int>(n,INT_MAX-1));
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    ans[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(auto x:dir){
                int nr=r+x[0];
                int nc=c+x[1];
                if(nr>=0 && nc>=0 && nr<m && nc<n && mat[nr][nc]==1){
                    if(ans[nr][nc]==INT_MAX-1){
                        q.push({nr,nc});
                    }
                    ans[nr][nc]=min(ans[nr][nc],ans[r][c]+1);
                }
            }
        }
        return ans;
    }
};