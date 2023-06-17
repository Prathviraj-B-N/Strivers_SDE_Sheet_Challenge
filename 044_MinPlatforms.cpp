typedef struct t{
    int at;
    int dt;
} schedule;

bool cmp(schedule a, schedule b){
    return a.at < b.at;
}

int calculateMinPatforms(int at[], int dt[], int n) {
  schedule s[n];

  for (int i = 0; i < n; i++) {
    s[i].at = at[i];
    s[i].dt = dt[i];
  }

    sort(s,s+n,cmp);

    int ans = 1;

    priority_queue<int,vector<int>, greater<int>> halts; // deptime
    halts.push(s[0].dt);

    for(int i = 1 ;i < n ; i++){

        if(s[i].at <= halts.top()){
            halts.push(s[i].dt);
        }else{
            halts.pop();
            halts.push(s[i].dt);
        }

        ans = max(ans,(int)halts.size());

    }

    return ans;


}

// Better Approach
int calculateMinPatforms(int at[], int dt[], int n) {
    sort(at,at+n);
    sort(dt,dt+n);

    int i = 1;
    int j = 0;
    int ans = 1;
    int k = 1;
    
    while(i < n){
        if(at[i] <= dt[j]){
            k++;
            i++;
            ans = max(ans,k);
            continue;
        } 
          
        while (dt[j] < at[i]){
            k--;
            j++;
        }

    }

    return ans;
    
}