class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        unordered_map<int, vector<int>> mp;
        vector<int> ans;
        for(int i = 0; i< matrix.size(); ++i){
            for(int j =0 ; j < matrix[i].size(); ++j){
                mp[i+j].push_back(matrix[i][j]);
            }
        }
        for(int i = 0 ; i < mp.size(); ++i){
            if(i%2 == 0){
                for(auto it = mp[i].rbegin(); it != mp[i].rend(); it++)
                    ans.push_back(*it);
            }
            else{
                for(auto it = mp[i].begin(); it != mp[i].end(); it++)
                    ans.push_back(*it);
            }
        }
        return ans;
    }
};