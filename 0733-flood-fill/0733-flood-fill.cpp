class Solution {
vector<vector<int>> dir = {{1,  0}, {-1, 0},  {0, 1}, {0, -1}};
private:
    void dfs(int sr, int sc, vector<vector<int>>& image, int color, int initColor){
        image[sr][sc] = color;
        for(auto x: dir){
            int dr = sr + x[0];
            int dc = sc + x[1];
            if( dr >= 0 && dr<image.size() && dc >= 0 && dc<image[0].size() && image[dr][dc] == initColor)
                 dfs(dr, dc, image, color, initColor);
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initColor = image[sr][sc];
        if(initColor == color) return image;
        dfs(sr, sc, image, color, initColor);

        return image;
    }
};