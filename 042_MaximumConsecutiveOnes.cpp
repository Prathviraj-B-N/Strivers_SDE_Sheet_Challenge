int longestSubSeg(vector<int> &arr , int n, int k){
    int i = 0;
    int j = 0;

    while(j < n){

        if(arr[j] == 0) k--;
        if( k<0 ){
            if(arr[i] == 0) k++;
            i++;
        }
        j++;

    }

    return j-i;
}
