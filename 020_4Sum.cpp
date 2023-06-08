#include <bits/stdc++.h>

// O(n^3)

string fourSum(vector<int> arr, int target, int n) {
    sort(arr.begin(),arr.end());

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){

            int k = j+1;
            int l = n-1;

            while(k<l){
                int sum = arr[i] + arr[j] + arr[k] + arr[l];
                if(sum == target){
                    return "Yes";
                    while(k<n-1 && arr[k]==arr[k+1]) k++;
                    k++;
                    while(l > 0 && arr[l-1]==arr[l]) l--;
                    l--;
                }else if(sum > target){
                    while(l > 0 && arr[l-1]==arr[l]) l--;
                    l--;
                }else{
                    while(k<n-1 && arr[k]==arr[k+1]) k++;
                    k++;
                }
            }
        }
    }

    return "No";
}
