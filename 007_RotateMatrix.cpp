#include <bits/stdc++.h>

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    int t = 0, b = n-1;
    int l = 0, r = m-1;

    while(t < b && l < r){
        int ele = mat[t][l];

        for(int i = t; i < b ; i++){
            mat[i][l] = mat[i+1][l];
        }
        
        for(int i = l; i < r;i++){
            mat[b][i] = mat[b][i+1];
        }
        
        l++;
        
        for(int i = b; i > t; i--){
            mat[i][r] = mat[i-1][r];
        }
        
        for(int i = r; i >= l; i--){
            mat[t][i] = mat[t][i-1];
        }
        mat[t][l] = ele;
        b--;
        r--;
        t++;
    }

}