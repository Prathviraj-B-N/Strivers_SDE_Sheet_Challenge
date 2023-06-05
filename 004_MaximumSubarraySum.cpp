#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    if(n == 0) return 0;

    long long ans = arr[0];
    long long sum = 0;
    

    for(int i = 0 ; i < n ; i++ ){
        sum += arr[i];
        ans = max(ans,sum);
        if(sum < 0) sum = 0;
    }
    return (ans < 0)?0:ans;

}