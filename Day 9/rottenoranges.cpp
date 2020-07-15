// HAD TO LOOK UP THE SOLUTION

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int i,j,count = -1, fresh = 0,newi,newj;
        vector<vector<int>> indices ={{-1,0},{1,0},{0,-1},{0,1}};
        for(i =0 ;i<grid.size();++i){
            for(j=0;j<grid[i].size();++j){
                if(grid[i][j] == 2)
                    q.push({i,j});
                else if(grid[i][j] == 1)
                    fresh++;
            }
        }
        if(fresh == 0)
            return 0;
        while(!q.empty()){
            count++;
            int currentsize = q.size();
            for(int y = 0; y < currentsize; y++)
            {
            i = q.front().first;
            j = q.front().second;
            q.pop();
            //count++;
            
            for(int k = 0; k<4;k++){
                newi = i + indices[k][0];
                newj = j + indices[k][1];
                if(newi < 0 || newj < 0 || newi >= grid.size() || newj >= grid[0].size() || grid[newi][newj] != 1)
                    continue;
                grid[newi][newj] = 2;
                fresh--;
                q.push({newi,newj});
            }
            }
        }
        return fresh == 0 ? count : -1;
    }
};