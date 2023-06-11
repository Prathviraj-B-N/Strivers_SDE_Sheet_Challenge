bool canPlace(vector<vector<int>>& board,int i,int j,int n){
    //check row
    for(int k = 0; k < j; k++) if(board[i][k]) return false;

    //check col
    for(int k = 0; k < i; k++) if(board[k][j]) return false;

    //check diag
    int ni = i-1;
    int nj = j-1;

    while(ni > -1 && nj > -1){
        if(board[ni][nj]) return false;
        ni--;
        nj--;
    }

     ni = i-1;
     nj = j+1;

    while(ni > -1 && nj < n){
        if(board[ni][nj]) return false;
        ni--;
        nj++;
    }

    return true;

}

void sol(int n,int i,int j,vector<vector<int>>& board,vector<vector<int>> &ans){
    // cout<<i<<" "<<j<<endl;
    if(j == n) return;
    if(i == n){
        vector<int> temp;
        for(int k = 0; k < n; k++){
            for(int l = 0; l < n; l++) temp.push_back(board[k][l]);
        }
        ans.push_back(temp);
        return;
    }

    if (canPlace(board, i, j, n)) {
       board[i][j] = 1;
       sol(n,i+1,0,board,ans);
    }
    board[i][j] = 0;
    sol(n,i,j+1,board,ans);
}

vector<vector<int>> solveNQueens(int n) {
    vector<vector<int>> ans;
    vector<vector<int>> board(n,vector<int>(n,0));
    sol(n, 0, 0, board ,ans);
    return ans;
}