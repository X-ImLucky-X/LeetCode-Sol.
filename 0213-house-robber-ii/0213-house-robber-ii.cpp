class Solution {
public:
    
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[n-1];
        unordered_map<int,int> mp1,mp2;
        return max(helper(0,n-2,nums,mp1),helper(1,n-1,nums,mp2));
    }
private:
    int helper(int i,int n,vector<int>& nums,unordered_map<int,int>& mp){
        if(i>n)return 0;
        if(mp.find(i)!=mp.end())return mp[i];
        mp[i]=max(helper(i+1,n,nums,mp),nums[i]+helper(i+2,n,nums,mp));
        return mp[i];
    }
};