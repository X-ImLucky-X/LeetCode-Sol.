class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& Grid) {
        int m=Grid.size();
        int n=Grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        if(Grid[0][0]==1 || Grid[m-1][n-1]==1)return 0;
        dp[0][0]=1;
        for(int i=1;i<m;i++){
            if(Grid[i][0]==0){
                dp[i][0]=dp[i-1][0];
            }
        }
        for(int j=1;j<n;j++){
            if(Grid[0][j]==0){
                dp[0][j]=dp[0][j-1];
            }
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(Grid[i][j]!=1){
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
};