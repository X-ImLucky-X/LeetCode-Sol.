class Solution {
private:
    void dfs(int i,int j,int n,string& st,vector<string>& res){
        if(i==j && i==n){
            res.push_back(st);
            return;
        }

        if(i<n){
            st+='(';
            dfs(i+1,j,n,st,res);
            st.pop_back();
        }
        if(j<i){
            st+=')';
            dfs(i,j+1,n,st,res);
            st.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string st;
        dfs(0,0,n,st,res);
        return res;
    }
};