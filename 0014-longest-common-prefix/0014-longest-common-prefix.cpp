class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans=strs[0];
        int i=1;
        while(i<strs.size()){
            while(strs[i].find(ans)!=0){
                ans.pop_back();
            }
            i++;
        }
        return ans;
    }
};