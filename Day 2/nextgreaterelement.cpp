//SOLUTION 1
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(nums.size(),-1);
        for(int i = 0;i < nums.size(); ++i){
            for(int j = i+1; j!=i; j++){
                if(j>=nums.size()){
                    j = -1;
                    continue;
                }
                if(nums[j] > nums[i]){
                    res[i] = nums[j];
                    break;
                }
                
            }
        }
        return res;
    }
};