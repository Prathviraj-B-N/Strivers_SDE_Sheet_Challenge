// O(log(m * n) * (m * n))

int count(vector<vector<int>> &matrix,int num){
    int count = 0;
    for(auto row:matrix){
        for(auto val:row)
            if(val <= num) count++;
    }

    return count;
}

int getMedian(vector<vector<int>> &matrix)
{
    int l = 0;
    int r = 10e9;

    int n = matrix[0].size() * matrix.size();

    while(l <= r){
        int mid = (l+r)/2;

        if(count(matrix,mid) <= n/2){
            l = mid+1;
        }else{
            r = mid-1;
        }
    }
    return l;
}