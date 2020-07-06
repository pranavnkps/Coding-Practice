class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if(nums.empty())
            return 0;
        if(nums.size() == 1)
            return nums[0];
        if(nums.size() == 2)
            return max(nums[0],nums[1]);
            
        int dp[100],i;
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        for(i=2; i<nums.size(); i++){
             dp[i] = max((dp[i-2]+nums[i]),(dp[i-1]));
        }
        return dp[size-1];
    }
};