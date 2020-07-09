//SOLUTION 1 - USING BUBBLE SORT
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if(*max_element(nums.begin(), nums.end()) == 0)
           return "0";
        vector<string> nums_string;
        string ans;
        for(int x : nums ){
            nums_string.push_back(to_string(x));
        }
        for(int i = 0; i<nums_string.size()-1; ++i){
            for(int j = 0; j<nums_string.size()-i-1; ++j){
                auto ab = nums_string[j] + nums_string[j+1];
                auto ba = nums_string[j+1] + nums_string[j];
                if(ba > ab)
                    swap(nums_string[j], nums_string[j+1]);    
            }
        }
        for(string s:nums_string){
            ans += s;
        }
        return ans;
    }
};