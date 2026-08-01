class Solution {
private:
    // void solve(int i, int j, vector<int>& nums, vector<vector<int>> &dp){
    //     if(i>=j) return;

    //     //if(dp[][] == -1) return dp[][];

    //     int take1 = solve(i+1,j);
    //     int take2 = solve(i,j-1);

    //     dp[][] = max(take1, take2);
    // }
    bool solve(int i, int j, long long a, long long b, vector<int>& nums, int flag){
        if (i > j)
            return a >= b;

        if (i == j) {
            if(flag == 0)
                a += nums[i];
            else
                b += nums[i];

            return a >= b;
        }
        if(flag == 0){
            bool take1 = solve(i+1, j, a + 1LL*nums[i], b, nums, 1);
            bool take2 = solve(i, j-1, a + 1LL*nums[j], b, nums, 1);
            return take1 || take2;
        }else{
            bool take1 = solve(i+1, j, a, b + 1LL*nums[i], nums, 0);
            bool take2 = solve(i, j-1, a, b + 1LL*nums[j], nums, 0);
            return take1 && take2;
        }
        return true;
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        //vector<vector<int>> dp(n, vector<int>(2,-1));
        // solve(0,n-1, dp);
        // return dp[n/2,0] > dp[n/2,1];
        return solve(1,n-1, 1LL*nums[0], 0, nums, 1) || solve(0,n-2, 1LL*nums[n-1], 0, nums, 1);
        
    }
};
