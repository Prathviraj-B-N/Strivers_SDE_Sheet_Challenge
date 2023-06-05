#include <bits/stdc++.h> 
int merge(vector<int> &arr,int l1, int r1, int l2, int r2){
    vector<int> temp;
    int i = l1;
    int j = l2;
    int count = 0;

	for(int k = l1; k <=r1; k++){
		while(j<=r2 && arr[k] > 2*arr[j]) j++;
		count += (j - l2);
	}

	i = l1;
    j = l2;
    while(i <= r1 && j <= r2){
		if(arr[i] <= arr[j]){
            temp.push_back(arr[i++]);
        }else{
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
int mergeSort(vector<int> &arr, int low, int high){
    if(low >= high) return 0;
    int mid = (low+high)/2;
    int count = mergeSort(arr,low,mid);
    count += mergeSort(arr,mid+1,high);
    count += merge(arr,low,mid,mid+1,high);
    return count;
}
int reversePairs(vector<int> &arr, int n){
	return mergeSort(arr,0,n-1);	
}