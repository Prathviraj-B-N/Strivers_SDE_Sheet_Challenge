// T O(n)
// S O(2 * n)
#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){

    long ltor[n];
    memset(ltor,0,sizeof(ltor));

    long rtol[n];
    memset(rtol,0,sizeof(rtol));

    long maxx = arr[0];
    ltor[0] = arr[0];
    for(int i = 1; i<n;i++){
        maxx = max(maxx,arr[i]);
        ltor[i] = maxx;

    }

    maxx = arr[n-1];
    rtol[n-1] = arr[n-1];
    for(int i = n-1; i>=0;i--){
        maxx = max(maxx,arr[i]);
        rtol[i] = maxx;
    }

    long ans= 0;

    for(int i = 0; i< n;i++){
        long tmp = (ltor[i]<=rtol[i])? (ltor[i] - arr[i]) : (rtol[i] - arr[i]);
        if(tmp > 0) ans += tmp;
    }

    return ans;

}