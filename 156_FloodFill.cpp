
#include<queue>
vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    vector<vector<int>> ans;
    int n = image.size();
    int m = image[0].size();

    vector<vector<int>> vis(n,vector<int>(m,0));

    queue<pair<int,int>> q;
    q.push({x,y});
    int val = image[x][y];

    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        
        if(vis[i][j]==1) continue;
        vis[i][j] = 1;
        if(image[i][j] == val){
            image[i][j] = newColor;
            if(i-1 >=0)q.push({i-1,j});
            if(j-1 >=0)q.push({i,j-1});
            if(i+1 < n)q.push({i+1,j});
            if(j+1 < m)q.push({i,j+1});
        }
    }
    return image;
}