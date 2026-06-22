class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        helper(0,{},nums);
        return res;
    }
private:
    void helper(int idx,vector<int> temp,vector<int>& nums){
        res.push_back(temp);
        for(int j=idx;j<nums.size();j++){
            if(j>idx && nums[j]==nums[j-1]){
                continue;
            }
            temp.push_back(nums[j]);
            helper(j+1,temp,nums);
            temp.pop_back();
        }
    }
};