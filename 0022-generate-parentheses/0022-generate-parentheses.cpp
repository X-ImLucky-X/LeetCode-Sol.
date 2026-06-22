class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string stack;
        dfs(0,0,n,stack,res);
        return res;
    }
private:
    void dfs(int OpenN,int CloseN,int n,string& stack,vector<string>& res){
        if(OpenN==CloseN && OpenN==n){
            res.push_back(stack);
            return;
        }
        if(OpenN<n){
            stack+='(';
            dfs(OpenN+1,CloseN,n,stack,res);
            stack.pop_back();
        }
        if(CloseN<OpenN){
            stack+=')';
            dfs(OpenN,CloseN+1,n,stack,res);
            stack.pop_back();
        }
    }
};