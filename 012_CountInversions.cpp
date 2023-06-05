// T:O(nlogn)
// S:O(n) for temp in merge()

#include <bits/stdc++.h> 
#define ll long long

ll merge(ll *arr,int l1, int r1, int l2, int r2){
    vector<int> temp;
    int i = l1;
    int j = l2;
    ll count = 0;

    while(i <= r1 && j <= r2){
        if(arr[i] <= arr[j]){
            temp.push_back(arr[i++]);
        }else{
            count+= (l2-i);
            temp.push_back(arr[j++]);
        }
    }

    while( i <= r1){
        temp.push_back(arr[i++]);
    }
    while( j <= r2){
        temp.push_back(arr[j++]);
    }

    for(int k = 0; k < temp.size(); k++){
        arr[l1+k] = temp[k];
    }

    return count;
}

ll mergeSort(ll *arr, int low, int high){
    if(low >= high) return 0;
    int mid = (low+high)/2;
    ll count = mergeSort(arr,low,mid);
    count += mergeSort(arr,mid+1,high);
    count += merge(arr,low,mid,mid+1,high);
    return count;
}

long long getInversions(long long *arr, int n){
    return mergeSort(arr,0,n-1);
}