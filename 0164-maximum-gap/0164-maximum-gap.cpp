class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()<2){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int maxgap=0;
        for(int i=0;i<nums.size()-1;i++){
            maxgap=max(maxgap,nums[i+1]-nums[i]);
        }
        return maxgap;
    }
};