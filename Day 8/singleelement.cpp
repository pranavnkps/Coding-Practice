//SOLUTION 1
class Solution {
public:
    int ans;
    int singleNonDuplicate(vector<int>& nums) {
        recurse(nums,0,nums.size()-1);
        return ans;
    }
    
    void recurse(vector<int> nums, int l, int r){
        int mid = (l+r)/2;
        if(l == r){
            ans = nums[l];
            return;
        }
        if(nums[mid+1] != nums[mid] && nums[mid-1] != nums[mid]){
            ans = nums[mid];
            return;
        }
        if(nums[mid-1] == nums[mid]){
            if((mid-2)%2 == 0 && (mid-2) >= l)
                recurse(nums,l,mid-2);
            else
                recurse(nums,mid+1,r);
                
        }
        else if(nums[mid+1] == nums[mid]){
            if((mid+2) <= r && (r-mid+2)%2 == 0)
                recurse(nums, mid+2, r);
            else
                recurse(nums, l, mid-1);
        }
    }
};

//SOLUTION 2 - MORE UNDERSTANDABLE
// For pairs of numbers before the single element appears, the first element of the pair will have even index and the second 
// element of the pair will have odd index.
// But after the single element appears, the first element of the pair will have odd index and the second element of the
// pair will have even index.

// So, if the index of a number is even and the same number is found in index+1, that means the single element has not 
// appeared yet as the ordering is right, thus the single element must be to the right of index+1
// If the same number is not found in index+1, then that means that the ordering has been disturbed and hence the single element
// is to the left of index(including index)
// Similarly for the case when the index of a number is odd......


class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        while(l<r){
            int mid = (l+r)/2;
            if(mid%2 == 0){                     
                if(nums[mid] == nums[mid+1])
                    l = mid+2;
                else
                    r = mid;
            }
            if(mid%2 == 1){
                if(nums[mid] == nums[mid-1])
                    l = mid+1;
                else
                    r = mid;
            }
        }
        return nums[l];
    }
};