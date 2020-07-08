class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1)
            return 0;
        int j=0,count=0,prod=1;
        for(int i=0; i<nums.size();++i){
            prod *= nums[i];
            while(prod >= k) {
                prod /= nums[j];
                j++;
            }
            count += i-j+1;
            
        }
     return count;   
    }
};