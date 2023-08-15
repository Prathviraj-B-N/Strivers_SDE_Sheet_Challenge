// bitmasking
//https://codeforces.com/problemset/problem/1042/B
int getMask(string s){
  int mask = 0;
  for(auto x:s){
    if(x == 'A') mask = mask | 1;
    else if(x == 'B') mask = mask | (1<<1);
    else mask = mask | (1<<2);
  }
  return mask;
}

void solve() {
  int n;
  cin>>n;

  vector<pair<int,int>> bottles; // state, cost
  
  bottles.push_back({0,0});
  for(int  i = 0; i < n; i++){
    int cost;
    string v;
    cin>>cost>>v;
    bottles.push_back({getMask(v),cost});
  }
  vector<int> minCost(8,1000001);
 
  // base case
  for(auto x:bottles){
    minCost[x.first] = min(minCost[x.first],x.second);
  }
  
  for(int i = 1; i < 8; i++){
    for(int j = i+1; j < 8; j++){
      minCost[i | j] = min(minCost[i | j],minCost[i]+minCost[j]);
    }
  }
    
  if(minCost[7] == 1000001) cout<<-1<<endl;
  else cout<<minCost[7]<<endl;

}