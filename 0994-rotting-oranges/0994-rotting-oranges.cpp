class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> visited;
        int fresh=0;
        int time=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    visited.push({i,j});
                }
                if(grid[i][j]==1){
                    fresh++;
                }
            }
        }

        vector<vector<int>> dir={{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while(!visited.empty() && fresh>0){
            int size=visited.size();
            while(size--){
                auto curr=visited.front();
                visited.pop();
                int rows=curr.first;
                int cols=curr.second;
                for(auto x:dir){
                    int newrows=rows+x[0];
                    int newcols=cols+x[1];
                    if(newrows >= 0 && newrows < grid.size() && newcols >= 0 && newcols < grid[0].size() && grid[newrows][newcols] == 1){
                        grid[newrows][newcols]=2;
                        visited.push({newrows,newcols});
                        fresh--;
                    }
                }
            }
            time++;
        }
        return (fresh==0?time:-1);
    }
};