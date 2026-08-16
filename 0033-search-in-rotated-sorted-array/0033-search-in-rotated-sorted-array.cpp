class Solution {
public:
    int search(vector<int>& nums, int target) {
        //phase 1:find the separation:
        int left=0;
        int right=nums.size()-1;
        int sep=0;
        while(left<right){
            int mid=left+((right-left)/2);
            if(nums[mid]<=nums[right]){
                right=mid;
            }else{
                left=mid+1;
            }
        }
        sep=left;

        //phase 2:find the target in two sorted arrays

        left=0;
        right=sep-1;
        while(left<=right){
            int mid=left+((right-left)/2);
            if(nums[mid]==target){
                return mid;
            }else if(nums[mid]<target){
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        left=sep;
        right=nums.size()-1;
        while(left<=right){
            int mid=left+((right-left)/2);
            if(nums[mid]==target){
                return mid;
            }else if(nums[mid]<target){
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        return -1;
    }
};