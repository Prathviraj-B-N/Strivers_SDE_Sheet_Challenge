int search(int* arr, int n, int key) {
    int l = 0;
    int r = n-1;

    while(l <= r){
        int mid = (l+r)/2;

        if(arr[mid] == key) return mid;
        else if(arr[0] <= arr[mid-1]){
            if(key >= arr[0] && key <= arr[mid-1]){
                r = mid-1;
            }else{
                l = mid+1;
            }
        }else{
            if(key >= arr[mid+1] && key <= arr[r]){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
    }
    return -1;
}