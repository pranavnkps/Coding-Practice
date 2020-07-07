class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc] == newColor)
            return image;
        int temp = image[sr][sc];
        image[sr][sc] = newColor;
        if((sr-1) >= 0)
            if(image[sr-1][sc] == temp)
                floodFill(image,sr-1,sc,newColor);
        if((sc-1) >= 0)
            if(image[sr][sc-1] == temp)
                floodFill(image,sr,sc-1,newColor);
        if((sr+1) <image.size())
            if(image[sr+1][sc] == temp)
                floodFill(image,sr+1,sc,newColor);
        if((sc+1) < image[0].size())
            if(image[sr][sc+1] == temp)
                floodFill(image,sr,sc+1,newColor);
        return image;
    }
};