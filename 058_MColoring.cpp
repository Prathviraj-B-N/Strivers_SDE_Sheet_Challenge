// O(N^m) where N : nodes ; m : colours
#include <bits/stdc++.h> 

bool canColor(int node,unordered_map<int,int> &mp,int clr,vector<vector<int>> &mat, int n){
    for(int i = 0; i < n; i++){
        if(i!=node && mat[node][i] == 1){
            if(mp.find(i) != mp.end() && mp[i] == clr) return false;
        }
    }
    return true;
}

bool sol(int idx,int n,unordered_map<int,int> &mp,vector<vector<int>> &mat,int m,int count){
    if(idx == n) return true;

        for(int clr = 0; clr<m;clr++){
            if(canColor(idx,mp,clr,mat,n)){
                mp[idx] = clr;
                if(sol(idx+1,n,mp,mat,m,count+1)) return true;
                mp.erase(idx);
            }
            
        }

    return false;
}

string graphColoring(vector<vector<int>> &mat, int m) {
    int n = mat[0].size();
    if(n == m) return "YES";

    unordered_map<int,int> mp;
    
    if(sol(0,n,mp,mat,m,0)) return "YES";
    return "NO";
}