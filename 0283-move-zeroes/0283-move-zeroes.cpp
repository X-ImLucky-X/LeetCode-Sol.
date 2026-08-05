class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0;
        for(int j=0;j<nums.size();j++){
            if(nums[j]!=0){
                swap(nums[i],nums[j]);
                i++;
            }
        }

        // i
        // j
        // 0,1,0,3,12

        // i j
        // 1,0,0,3,12

        //   i j
        // 1,0,0,3,12

        //   i   j
        // 1,3,0,0,12

        //      i   j
        // 1,3,12,0,0
        
    }
};