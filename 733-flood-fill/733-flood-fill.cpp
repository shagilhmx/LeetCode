class Solution {
public:
    void helper(vector<vector<int>>& image, int i, int j, int oldc, int newc, set<pair<int,int>> s, int n, int m) {
        if(s.find({i,j})==s.end())
        {
            s.insert({i,j});
            if(i<0 || i>=n || j<0 || j>=m || image[i][j]!=oldc)
                return ;
            image[i][j]=newc;
            helper(image,i,j+1,oldc,newc,s, n, m);
            helper(image,i,j-1,oldc,newc,s, n, m);
            helper(image,i-1,j,oldc,newc,s, n, m);
            helper(image,i+1,j,oldc,newc,s, n, m);
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)
    {
        int n=image.size();
        int m=image[0].size();
        set<pair<int,int>> s;
        helper(image,sr,sc,image[sr][sc],newColor,s, n, m);
        return image;
    }
};