class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return climb(0,n,dp);
    }
private:
    int climb(int i,int n,vector<int>& dp){
        if(i==n)return 1;
        if(i>n)return 0;
        if(dp[i]!=-1)return dp[i];
        int onestep=climb(i+1,n,dp);
        int twostep=climb(i+2,n,dp);
        return dp[i]=onestep+twostep;
    }
};