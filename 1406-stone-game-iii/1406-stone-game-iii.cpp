class Solution {
private:
    int solve(int i, vector<int>& stoneValue,  vector<int>& dp){
        if(i>= stoneValue.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int result = INT_MIN;
        result = max(result, stoneValue[i] - solve(i+1,stoneValue, dp));
        if(i + 1 < stoneValue.size())
            result = max(result, stoneValue[i] + stoneValue[i+1] - solve(i+2,stoneValue, dp));
        if(i + 2 < stoneValue.size())  
            result = max(result, stoneValue[i] + stoneValue[i+1] + stoneValue[i+2] - solve(i+3,stoneValue, dp));

        return dp[i] = result;
    }

public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        int sum = accumulate(stoneValue.begin(), stoneValue.end(), 0);
        vector<int> dp(n,-1);

        int alice = solve(0, stoneValue, dp);
        if(alice == 0) return "Tie";
        else if(alice < 0) return "Bob";
        else return "Alice";
    }
};