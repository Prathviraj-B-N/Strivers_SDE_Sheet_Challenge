void dfs(int i,int j,int n,int m,vector<vector<int>> &vis,vector<vector<char>> &mat){
        
    if(vis[i][j] == 1) return;
    if(mat[i][j] != 'O') return;
    
    vis[i][j] = 1;
    
    if(i-1 >= 0) dfs(i-1,j,n,m,vis,mat);
    if(i+1 < n) dfs(i+1,j,n,m,vis,mat);
    if(j-1 >= 0) dfs(i,j-1,n,m,vis,mat);
    if(j+1 < m) dfs(i,j+1,n,m,vis,mat);
}
    
vector<vector<char>> fill(int n, int m, vector<vector<char>> mat){
    // traversr boundary and dfs( all Os ) mark them visited
    vector<vector<int>> vis(n,vector<int>(m,0));
    
    for(int i = 0; i < m;i++){
        if(mat[0][i] == 'O' && vis[0][i]!=1) dfs(0,i,n,m,vis,mat);
    }
    
    for(int i = 0; i < m;i++){
        if(mat[n-1][i] == 'O' && vis[n-1][i]!=1) dfs(n-1,i,n,m,vis,mat);
    }
    
    for(int i = 1; i < n-1;i++){
        if(mat[i][0] == 'O' && vis[i][0]!=1) dfs(i,0,n,m,vis,mat);
    }
    
    for(int i = 1; i < n-1;i++){
        if(mat[i][m-1] == 'O' && vis[i][m-1]!=1) dfs(i,m-1,n,m,vis,mat);
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(mat[i][j] == 'O' && vis[i][j]!=1) mat[i][j] = 'X';
        }
    }
    
    return mat;
}