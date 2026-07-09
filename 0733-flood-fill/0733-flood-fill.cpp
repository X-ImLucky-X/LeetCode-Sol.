class Solution {
public:
    vector<vector<int>> dir = {{1,  0}, {-1, 0},  {0, 1}, {0, -1}};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>> q;
        int initcolor=image[sr][sc];
        if(initcolor==color)return image;
        q.push({sr,sc});
        image[sr][sc]=color;
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(auto x:dir){
                int nr=row+x[0];
                int nc=col+x[1];
                if(nr >= 0 && nr < image.size() && nc >= 0 && nc < image[0].size() && image[nr][nc] == initcolor){
                    image[nr][nc]=color;
                    q.push({nr,nc});
                }
            }
        }
        return image;
    }
};