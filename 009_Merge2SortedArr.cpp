#include <bits/stdc++.h>

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {

    int l=0;
    int r=0;

    vector<int> arr(m+n);
    int j = 0;

    while(l < m && r < n){
        if(arr1[l] <= arr2[r]) arr[j++] = arr1[l++];
        else arr[j++] = arr2[r++];
    }

    while(l < m) arr[j++] = arr1[l++];
    while(r < n) arr[j++] = arr2[r++];
    
    return arr;
}
