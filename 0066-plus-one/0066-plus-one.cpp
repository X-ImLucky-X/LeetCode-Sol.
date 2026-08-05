class Solution {
public:
    vector<int> plusOne(vector<int>& d) {
        reverse(d.begin(),d.end());
        int sum=0;
        int carry=1;
        for(int i=0;i<d.size();i++){
            sum=d[i]+carry;
            carry=sum/10;
            sum=sum%10;
            d[i]=sum;
        }
        if(carry)d.push_back(carry);
        reverse(d.begin(),d.end());
        return d;
    }
};