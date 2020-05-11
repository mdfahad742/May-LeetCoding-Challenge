// VERY STANDARD QUESTION ON DFS ON MATRIX.  :)
class Solution {
public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    int n,m;
    
    map<pair<int,int>, bool> vis;
    
    void dfs(int x,int y,vector<vector<int>>& image,int newColor,int curColor){
        vis[{x,y}]=1;
        image[x][y]=newColor;
        for(int i=0;i<4;i++){
            int X=x+dx[i],Y=y+dy[i];
            if(X<0 || X>=n || Y<0 || Y>m)continue;
            if(!vis[{X,Y}] && curColor==image[X][Y])dfs(X,Y,image,newColor,curColor);
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        n=image.size();
        m=image[0].size();
        if(n==0 || m==0)return image;
        dfs(sr,sc,image,newColor,image[sr][sc]);
        return image;
    }
};
