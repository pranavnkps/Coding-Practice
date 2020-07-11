class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if(matrix.empty())
            return ans;
        int rst = 0, cst = 0, rend = matrix.size()-1, cend = matrix[0].size()-1, i;
        while(rst <= rend && cst <= cend){
            for(i = cst; i<=cend;i++){
                ans.push_back(matrix[rst][i]);
            }
            rst++;
            for(i = rst; i <= rend; i++ ){
                ans.push_back(matrix[i][cend]);
            }
            cend--;
            if(rst > rend || cst > cend)
                break;
            for(i=cend ; i >= cst ; --i){
                ans.push_back(matrix[rend][i]);
            }
            rend--;
            for(i=rend; i>=rst; --i){
                ans.push_back(matrix[i][cst]);
            }
            cst++;
        }
        return ans;
    }
};