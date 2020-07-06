class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> output;
        vector<int> temp;
        for(int j = 0; j < numRows; j++){
            temp.clear();
            for(int i = 0 ; i<=j; i++){
                if(i == 0 || i == j)
                    temp.push_back(1);
                else
                    temp.push_back(output[j-1][i-1] + output[j-1][i]);
            }  
            output.push_back(temp);
        }
        return output;
        
    }
};
