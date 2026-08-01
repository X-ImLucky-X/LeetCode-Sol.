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
        for(int length=2;length<=n;length++){
            for(int i=0;length+i-1<n;i++){
                int j=length+i-1;
                int left=nums[i]-dp[i+1][j];
                int right=nums[j]-dp[i][j-1];
                dp[i][j]=max(left,right);
            }
        }
        return dp[0][n-1]>=0;
    }
};