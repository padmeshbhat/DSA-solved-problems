class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        
        int oldcolor=image[sr][sc];
        if(color==oldcolor){
            return image;
        }
        queue<pair<int,int>>q;
        q.push({sr,sc});
        image[sr][sc]=color;
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();

            // 4 directions

            // up
            if(row-1 >= 0 && image[row-1][col] == oldcolor) {
                image[row-1][col] = color;
                q.push({row-1,col});
            }

            // down
            if(row+1 < n && image[row+1][col] == oldcolor) {
                image[row+1][col] = color;
                q.push({row+1,col});
            }

            // left
            if(col-1 >= 0 && image[row][col-1] == oldcolor) {
                image[row][col-1] = color;
                q.push({row,col-1});
            }

            // right
            if(col+1 < m && image[row][col+1] == oldcolor) {
                image[row][col+1] = color;
                q.push({row,col+1});
            }
        }
        return image;
        
    }
};