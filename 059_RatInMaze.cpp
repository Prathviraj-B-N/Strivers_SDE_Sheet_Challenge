#include <bits/stdc++.h> 
void sol(int i,int j,vector<int> &temp, vector<vector<int>> &vis, vector<vector<int>>& ans, vector<vector<int>> &maze,int n){
  if(i < 0 || i >= n || j < 0 || j >=n) return;
  

  if(i == n-1 && j == n-1){
    temp[(i+1) * (i+1) - 1] = 1;
    ans.push_back(temp);
    temp[(i+1) * (i+1) - 1] = 0;
  }



  vis[i][j] = 1;
  temp[i*n + j%n] = 1;
  // left 
  if(j > 0 && maze[i][j-1] != 0 && vis[i][j-1]!=1) sol(i,j-1,temp, vis,ans,maze,n);

  // right
  if(j < n-1 && maze[i][j+1]!=0 && vis[i][j+1]!=1) sol(i,j+1,temp, vis,ans,maze,n);

  // up
  if(i > 0 && maze[i-1][j] != 0 && vis[i-1][j]!=1) sol(i-1,j,temp, vis,ans,maze,n);

  // down
  if(i < n-1 && maze[i+1][j] != 0 && vis[i+1][j]!=1) sol(i+1,j,temp, vis,ans,maze,n);

  temp[i*n + j%n] = 0;
  vis[i][j] = 0;

}
vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
  vector<vector<int>> ans;
  vector<vector<int>> vis(n,vector<int> (n,0));
  vector<int> temp(n*n,0);
  sol(0, 0, temp, vis, ans, maze, n);

  return ans;
}