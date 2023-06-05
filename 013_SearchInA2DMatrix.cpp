// T: O(log m*n)

bool searchMatrix(vector<vector<int>>& mat, int target) {
    int rows = mat.size();
    int cols = mat[0].size();

    int l = 0;
    int r = rows*cols - 1;

    while(l <= r){
        int mid = (l+r)/2;
        if(mat[mid/cols][mid%cols] == target) return true;
        else if(target > mat[mid/cols][mid%cols]){
            l = mid+1;
        }
        else r = mid-1;
    }

    return false;
    
}