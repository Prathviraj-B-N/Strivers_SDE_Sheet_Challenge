int check(vector<int> &vis){
    int n = vis.size();
    for(int i = 1; i < n; i++){
        if(vis[i] == 0) return i;
    }
    return -1;
}

void bfs(int node,vector<vector<int>>& roads,vector<int> &vis){
    queue<int> q;
    q.push(node);

    while(!q.empty()){
        if(vis[q.front()] == 1){
            q.pop();
            continue;
        }
        auto adjlist = roads[q.front()-1];
        vis[q.front()] = 1;
        for(int i = 0;i < adjlist.size();i++){
            if(adjlist[i] != 0) q.push(i+1);
        }
        q.pop();
    }
}

int findNumOfStates(vector<vector<int>>& roads, int n) {
    vector<int> vis(n+1,0);
    int ans = 0;
    while(1){
        int node = check(vis);
        if(node == -1) break;
        ans++;
        bfs(node,roads,vis);
    }

    return ans;
}