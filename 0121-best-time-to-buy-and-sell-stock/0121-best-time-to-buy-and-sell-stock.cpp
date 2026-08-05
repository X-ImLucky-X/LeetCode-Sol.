class Solution {
public:
    int maxProfit(vector<int>& p) {
        int ans=0;
        int minm=p[0];
        for(int i=1;i<p.size();i++){
            if(p[i]<minm){
                minm=p[i];
            }else{
                ans=max(ans,p[i]-minm);
            }
        }
        return ans;
    }
};