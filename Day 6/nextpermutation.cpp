//  SOLUTION 1
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        int i = size-1;
        //auto it = nums.begin();
        while(i > 0 && nums[i-1] >= nums[i])
            --i;
        if(i == 0)
            reverse(nums.begin(), nums.end());
        else{
            reverse(nums.begin()+i, nums.end());
            auto temp = upper_bound(nums.begin()+i-1,nums.end(), nums[i-1]);
            swap(*(nums.begin()+i-1),*temp);
        }
    }
};