#include <bits/stdc++.h> 
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    vector<int> ans(kArrays[0].begin(),kArrays[0].end());

    int n = kArrays.size();

    for(int i = 1; i < n;i++){
        int l=0;
        int r=0;
        int lmax = ans.size();
        int rmax = kArrays[i].size();
        vector<int> arr(lmax+rmax);
        int j = 0;

        while(l < lmax && r < rmax){
            if(ans[l] <= kArrays[i][r]){
                arr[j++] = ans[l++];
            }else{
                arr[j++] = kArrays[i][r++];
            }
        }
        while(l < lmax){
            arr[j++] = ans[l++];
        }
        while(r < rmax){
            arr[j++] = kArrays[i][r++];
        }

        for(int c = 0; c < lmax; c++){
            ans[c] = arr[c];
        }

        for(int c = lmax; c < (lmax+rmax); c++){
            ans.push_back(arr[c]);
        }
    }

    return ans;
}
