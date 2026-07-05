
class Solution {
    int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
public:
    int maxx = 0;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area = 0;

        int rows=grid.size();
        int cols=grid[0].size();

        for(int r=0;r<rows;r++){
            for(int c=0;c<cols;c++){
                if(grid[r][c]==1){
                    dfs(grid,r,c,area);

                    maxx = max(area,maxx);
                    area = 0;
                }
            }
        }
        return maxx;
    }
private:
    void dfs(vector<vector<int>>& grid,int r,int c,int& area){
        if(r<0 || c<0 || r>=grid.size() || c>=grid[0].size() || grid[r][c]==0){
                        
            return;
        }
        grid[r][c]=0;
        area++;
        for(int i=0;i<4;i++){
            dfs(grid,r+dir[i][0],c+dir[i][1],area);
        }
    }
};