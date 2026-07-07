class Solution {
public:
    int findCircleNum(vector<vector<int>>& c) {    
        int count = 0;
        vector<int>vis(c.size());
        for(int i = 0;i<c.size();i++){
            if(!vis[i]){
                count++;
                dfs(i,c,vis);
            }
        }
        return count;
    }
private:
    void dfs(int node,vector<vector<int>>&c,vector<int>&vis){
        vis[node] = 1;
        for(int i = 0;i < c.size(); i++){
            if(!vis[i] && c[node][i] == 1){
                dfs(i,c,vis);
            }
        }
    }
};