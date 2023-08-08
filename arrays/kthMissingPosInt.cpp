// Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.
// Return the kth positive integer that is missing from this array.

// O(n)
int findKthPositive(vector<int>& arr, int k) {
    int missingNumber = 1;
    int missingCount = 0;
    int n = arr.size();
    for(int i = 0; i < n; i++){
        if(missingNumber == arr[i]){
            missingNumber++;
        }else if(missingNumber < arr[i]){
            //see how many are missing
            int len = arr[i]-missingNumber;
            //len elements are missing
            //see if k value lies between this
            if(missingCount + len >= k){
                return missingNumber+k-missingCount-1;
            }else{ //skip len elements
                missingCount += len;
                missingNumber = arr[i]+1;
            }
        }
    }
    return missingNumber+k-1-missingCount;
}

// O(logn)
int findKthPositive(vector<int>& arr, int k) {
    int l = 0;
    int r = arr.size()-1;
    
    while(l <= r){
        int mid = l+(r-l)/2;
        int nowMissing = arr[mid] - (mid+1);
        if(nowMissing >= k){ // number of ele missing till i   
            r = mid-1;  
        }else {
            l = mid+1;
        }
        
    }
    // return arr[r] + k - (arr[r] - (r+1));
    // return k + (r+1);
    return k+l; //r+1 == l 
}