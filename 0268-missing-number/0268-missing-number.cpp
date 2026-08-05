class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<int> mp(nums.size()+1,-1);
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]=nums[i];
        }
        for(int i=0;i<mp.size();i++){
            if(mp[i]==-1)return i;
        }
        return 0;
    }
};