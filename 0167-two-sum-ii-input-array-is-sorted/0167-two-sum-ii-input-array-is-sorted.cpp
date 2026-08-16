class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        //brute force : works but ....nah
        // int n=numbers.size();
        // for(int i=0;i<n-1;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(numbers[i]+numbers[j]==target)return {i+1,j+1};
        //     }
        // }
        // return {};

        //two pointer
        int n=numbers.size();
        int left=0;
        int right=n-1;
        while(left<right){
            if(numbers[left]+numbers[right]==target)return {left+1,right+1};
            if(numbers[left]+numbers[right]>target)right--;
            if(numbers[left]+numbers[right]<target)left++;
        }
        return {};
    }
};