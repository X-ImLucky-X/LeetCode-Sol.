class Solution {
private:
    bool solve(int i,int j,long long a,long long b,vector<int>& nums,int flag){
        if(i>j)return a>=b;
        if(i==j){
            if(flag==0){
                a+=nums[i];
            }else{
                b+=nums[i];
            }
            return a>=b;
        }
        if(flag==0){
            bool t1=solve(i+1,j,a+1LL*nums[i],b,nums,1);
            bool t2=solve(i,j-1,a+1LL*nums[j],b,nums,1);
            return t1 || t2;
        }else{
            bool t1=solve(i+1,j,a,b+1LL*nums[i],nums,0);
            bool t2=solve(i,j-1,a,b+1LL*nums[j],nums,0);
            return t1 && t2;
        }
        return true;

    }
public:
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        return solve(1,n-1,1LL*nums[0],0,nums,1) || solve(0,n-2,1LL*nums[n-1],0,nums,1);
    }
};