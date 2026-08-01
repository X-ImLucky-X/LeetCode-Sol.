class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        //observation:even element in array ensure player 1 wins
        if(n%2==0)return true;
        //for odd number of elements : using dp
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            dp[i][i]=nums[i];
        }
        for(int j=2;j<=n;j++){
            for(int k=0;j+k-1<n;k++){
                int x=j+k-1;
                int left=nums[k]-dp[k+1][x];
                int right=nums[x]-dp[k][x-1];
                dp[k][x]=max(left,right);
            }
        }
        return dp[0][n-1]>=0;
    }
};