
int bs(vector<vector<int>> &mat,int i){
    int m = mat.size();
    int n = mat[0].size();

    int l = 0;
    int r = n-1;
    
    while(l <= r){
        int mid = l+(r-l)/2;
    
        int prev = (mid < 1)?-1:mat[i][mid-1];
        int next = (mid > n-2)?-1:mat[i][mid+1];
        int top  = (i < 1)?-1:mat[i-1][mid];
        int bottom = (i > m-2)?-1:mat[i+1][mid];
    
        if(mat[i][mid] > prev && mat[i][mid] > next && mat[i][mid] > top && mat[i][mid] > bottom) return mid;
    
        int leftColMax = -1;
        int rightColMax = -1;

        if(mid > 0) for(int p = 0; p < m; p++) leftColMax = max(leftColMax, mat[p][mid-1]);
        if(mid < n-1) for(int p = 0; p < m; p++) rightColMax = max(rightColMax, mat[p][mid+1]);

        if(leftColMax > rightColMax) r = mid-1;
        else l = mid+1;
    }
    return -1;
}

vector<int> findPeakGrid(vector<vector<int>>& mat) {
    int n = mat.size();
    for(int i = 0;i < n; i++){
        int a = bs(mat,i);
        if(a!=-1) return {i,a};
    }
    return {};
}
