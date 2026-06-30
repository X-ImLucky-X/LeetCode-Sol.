class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
        int ans=helper(coins,amount,dp);
        return ans==INT_MAX-1?-1:ans;
    }
private:
    int helper(vector<int>& coins,int amount,vector<int>& dp){
        if(amount==0)return 0;
        if(amount<0)return INT_MAX - 1;
        if(dp[amount]!=-1)return dp[amount];
        int minx=INT_MAX-1;
        for(int coin:coins){
            minx=min(minx,1+helper(coins,amount-coin,dp));
        }
        return dp[amount]=minx;
    }
};