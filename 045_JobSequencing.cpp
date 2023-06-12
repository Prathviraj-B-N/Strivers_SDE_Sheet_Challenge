#include <bits/stdc++.h> 

bool cmp(vector<int> a,vector<int> b){
    return a[1] > b[1];
}

int jobScheduling(vector<vector<int>> &jobs)
{
    int n = jobs.size();
    sort(jobs.begin(),jobs.end(),cmp);

    int JSArraySize = 0; 
    for(int i = 0; i<n;i++){
        JSArraySize = max(jobs[i][0],JSArraySize);
    }
    
    vector<int> JSArr(JSArraySize+1,0);
    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = jobs[i][0]; j > 0; j--) {
           if (JSArr[j] == 0) {

              JSArr[j] = 1;
              ans += jobs[i][1];
              break;

           }

        }

     }

   return ans;

}
