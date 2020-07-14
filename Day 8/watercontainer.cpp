class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = INT_MIN, area;
        for(int i = 0, j = height.size()-1; i<j;){
            area = (j-i)*min(height[i],height[j]);
            if(area > max)
                max = area;
            if( min(height[i], height[j]) == height[i]){
                while(height[i+1]< min(height[i], height[j]))
                    i++;
                ++i;
            }
            else{
                while(height[j-1] <  min(height[i], height[j]))
                    --j;
                --j;
            }
        }
        return max;
    }
};