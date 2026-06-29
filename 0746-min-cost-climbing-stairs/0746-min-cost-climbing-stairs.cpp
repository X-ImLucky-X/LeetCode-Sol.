class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        unordered_map<int,int> mp;
        return min(helper(0,cost,mp),helper(1,cost,mp));
    }
private:
    int helper(int i,vector<int>& cost,unordered_map<int,int>& mp){
        if(i>=cost.size())return 0;
        if(mp.find(i)!=mp.end())return mp[i];

        mp[i]=cost[i] + min(helper(i+1,cost,mp),helper(i+2,cost,mp));
        return mp[i]; 
    }
};