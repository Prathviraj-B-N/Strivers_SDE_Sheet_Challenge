void dfs(int node,vector<vector<int>> &graph,vector<int> &temp,vector<int> &vis){
    if(vis[node] == 1) return;
    temp.push_back(node);
    vis[node] = 1;
    for(auto x:graph[node]) dfs(x,graph,temp,vis);
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<int> vis(V,0);
    vector<vector<int>> graph(V);
    vector<vector<int>> ans;

    for(auto x:edges){
        graph[x[0]].push_back(x[1]);
        graph[x[1]].push_back(x[0]);
    }

    for(auto x:graph){
        sort(x.begin(),x.end());
    }

    for(int i = 0; i < V;i++){
        if(vis[i] == 0){
            vector<int> temp;
            dfs(i,graph,temp,vis);
            ans.push_back(temp);
        }
    }

    return ans;

}