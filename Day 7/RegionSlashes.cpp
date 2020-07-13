class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        vector<vector<int>> newgrid(grid.size()*3, vector<int>(grid.size()*3,0));
        int count = 0;
        for(int i = 0 ; i < grid.size(); ++i){
            for(int j = 0 ; j < grid[i].size(); ++j){
                if(grid[i][j] == '/'){
                    newgrid[i*3][3*j+2] = 1;
                    newgrid[i*3+1][3*j+1] = 1;
                    newgrid[i*3+2][3*j] = 1;
                }
                if(grid[i][j] == '\\'){
                    newgrid[i*3][3*j] = 1;
                    newgrid[i*3+1][3*j+1] = 1;
                    newgrid[i*3+2][3*j+2] = 1;
                }
            }
        }
        for(int i =0 ; i<newgrid.size(); ++i){
            for(int j = 0; j<newgrid.size();++j){
                if(newgrid[i][j] == 0){
                    dfs(newgrid, i,j);
                    count++;
                }
            }
        }
        return count;
    }
    void dfs(vector<vector<int>>& newgrid, int i, int j){
        if(i<0 || i> newgrid.size()-1 || j<0 || j> newgrid.size()-1 || newgrid[i][j] == 1)
            return;
        newgrid[i][j] = 1;
        dfs(newgrid, i+1,j);
        dfs(newgrid, i-1,j);
        dfs(newgrid, i,j-1);
        dfs(newgrid, i,j+1);
        
    }
};