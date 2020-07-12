class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = INT_MIN, count;
        for(int i =0; i<grid.size(); i++){
            for(int j = 0; j < grid[0].size(); ++j){
                count = 0;
                dfs(grid, i, j, count);
                ans = max(ans, count);
            }
        }
        return ans;
    }
    
    void dfs(vector<vector<int>>& grid, int i, int j, int& count){
        if(i<0 || j<0 || i>=grid.size() || j>= grid[0].size() || grid[i][j] == 0)
            return;
        count++;
        grid[i][j] = 0;
        dfs(grid, i+1, j, count);
        dfs(grid, i-1, j, count);
        dfs(grid, i, j+1, count);
        dfs(grid, i, j-1, count);
    }
};