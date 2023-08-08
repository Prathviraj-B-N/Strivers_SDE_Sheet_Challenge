// O(n-k)
int findKRotation(vector<int> &arr){
    int i = arr.size()-1;
    while(i > 0 && arr[i] > arr[i-1]) i--;
    if(i == 0) return 0;
    return i;
}

// we observe we just have to find the lowest element of the array and return the index
// O(logn)
int findKRotation(vector<int> &arr){
    int l = 0;
    int h = arr.size()-1;
    int least = 1e9;
    int leastIdx = -1;

    while(l <= h){
        int mid = l+(h-l)/2;
        //whole arr is sorted
        if(arr[l] <= arr[h]){
            if(least > arr[l]){
                leastIdx = l;
                break;
            }
        }
        
        // left is sorted then min element is at low
        if(arr[l]<=arr[mid]){
            if(least > arr[l]){
                least = arr[l];
                leastIdx = l;
            }
            l = mid+1;
        }else{
        // right is sorted then min element is at high
            if(least > arr[mid]){
                least = arr[mid];
                leastIdx = mid;
            }
            h = mid-1;
        }
    }

    return leastIdx;

}

