class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> cur;
        dfs(0,s,cur,res);
        return res;
    }
private:
    void dfs(int i,const string& s,vector<string>& cur,vector<vector<string>>& res){
        if(i>=s.size()){
            res.push_back(cur);
            return;
        }
        for(int j=i;j<s.size();j++){
            if(ispal(s,i,j)){
                cur.push_back(s.substr(i,j-i+1));
                dfs(j+1,s,cur,res);
                cur.pop_back();
            }
        }
    }
    bool ispal(const string& s,int l,int r){
        while(l<r){
            if(s[l]!=s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};