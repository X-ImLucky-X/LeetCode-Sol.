class Solution {
public:
    unordered_map<int,int> mp;
    int rob(vector<int>& nums) {
        return helper(0,nums);
    }
private:
    int helper(int i,vector<int>& nums){
        if(i>=nums.size())return 0;
        if(mp.find(i)!=mp.end())return mp[i];

        mp[i]=max(helper(i+1,nums),nums[i]+helper(i+2,nums));
        return mp[i];
    }
};