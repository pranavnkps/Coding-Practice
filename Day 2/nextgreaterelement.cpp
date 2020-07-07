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

//SOLUTION 2 - USING STACK
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(nums.size());
        stack<int> s;
        for(int i = nums.size()-1; i>=0; --i){
            while(!s.empty() && nums[s.top()] <= nums[i]){
                //res[s.top()] = nums[i];
                s.pop();   
            }
            if(s.empty()){
                res[i] = -1;
                s.push(i);
            }
            else{
                res[i] = nums[s.top()];
                s.push(i);
            }
        }
        for(int i = nums.size()-1; i>=0; --i){
            while(!s.empty() && nums[s.top()] <= nums[i]){
               // res[s.top()] = nums[i];
                s.pop();   
            }
            if(s.empty()){
                res[i] = -1;
                s.push(i);
            }
            else{
                res[i] = nums[s.top()];
                s.push(i);
            }
        }
        return res;
    }
};