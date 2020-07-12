class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> ans;
        unordered_map<int, vector<int>> mp;
            for(int j = 0 ; j < nums.size(); j++){
                for(int k = 0; k < nums[j].size(); k++)
                {
                        mp[j+k].push_back(nums[j][k]);     
                }
            }
        for(int i = 0; i < mp.size(); i++){
            for(auto it1 = mp[i].rbegin(); it1 != mp[i].rend(); it1++)
                ans.push_back(*it1);
        }
        return ans;
    }
};