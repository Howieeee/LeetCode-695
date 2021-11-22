class Solution {
public:
    
    void DFS(vector<vector<int>>& grid,int r, int c, int &area,vector<vector<int>>& has_visited){
        int row = grid.size()-1 , col = grid[0].size()-1;
        if(r<0 || r > row || c <0 || c > col || has_visited[r][c] == 1 || grid[r][c] != 1)
            return;
         
         has_visited[r][c] = 1;
        
         area++;
         DFS(grid,r-1,c,area,has_visited);
         DFS(grid,r+1,c,area,has_visited);
         DFS(grid,r,c-1,area,has_visited);
         DFS(grid,r,c+1,area,has_visited);
        
        
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        vector<vector<int>> has_visited(grid.size(),(vector<int>(grid[0].size(),0)));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                int t_area = 0;
                if(grid[i][j] == 1 && !has_visited[i][j]){//是1 且沒visit過
                    DFS(grid,i,j,t_area,has_visited);
                    has_visited[i][j] = 1;
                }
                if(t_area > max_area)
                    max_area = t_area;
            }
        }
       
        return max_area;
    }
};
