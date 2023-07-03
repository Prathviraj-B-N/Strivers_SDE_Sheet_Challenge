#include<bits/stdc++.h>


    /*
    2 1 1
    1 1 0
    1 1 1

    orangeCount = 8
    q: 00
    ans: 1
    qsize: 1
    badCount: 1

    pos {0,0}

    
    

    */

bool checkAndPush(vector<vector<int>> &a,pair<int,int> pos,queue<pair<int,int>> &q,int n,int m ){
    int i = pos.first;
    int j = pos.second;

    if(j-1>=0 && a[i][j-1] == 1) {a[i][j-1] = 2;q.push({i,j-1});}
    if(i+1<n && a[i+1][j] == 1) {a[i+1][j] = 2;q.push({i+1,j});}
    if(j+1<m && a[i][j+1] == 1) {a[i][j+1] = 2;q.push({i,j+1});}
    if(i-1>=0 && a[i-1][j] == 1) {a[i-1][j] = 2;q.push({i-1,j});}
    return true;
}
int minTimeToRot(vector<vector<int>>& a, int n, int m)
{
  
    int orangeCount = 0,badCount = 0;
    queue<pair<int,int>> q;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] > 0) orangeCount++;
            if(a[i][j] == 2) q.push({i,j});
        }       
    }

    int ans = 0;
    // now we have the job q ready
    while(!q.empty()){
        ans++;
        int qsize = q.size();
        badCount += qsize;

        for(int i = 0; i < qsize; i++){
            pair<int,int> pos = q.front();
            checkAndPush(a, pos, q,n,m);
            q.pop();
        }
    }
    ans = max(0,ans-1);
    return (badCount == orangeCount)?ans:-1;

}
    // count oranges and push to queue; 
    // we are using queue because an action a job(of rotting adj oranges) ; when a job completes we remove it
    // and add the jobs that inturn created

    /* return -1 for impossible case: if we dont rott all oranges ; 
       it means we can traverse the grid once agian and check if there are any 1s present
        or
       we can maintain a count and check at the end
    */