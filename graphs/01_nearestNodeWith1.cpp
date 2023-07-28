typedef struct node{
    int i;
    int j;
    int step;
} Node;

void pushToq(int i,int j,int step,queue<Node> &q){
    Node n;
    n.i = i;
    n.j = j;
    n.step = step;
    q.push(n);
    // cout<<"new Node Pushed "<<q.back().i<<" "<<q.back().j<<endl;
}
    
vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n = grid.size();
	    int m = grid[0].size();
	    
	    vector<vector<int>> vis(n,vector<int>(m,0));
	    vector<vector<int>> ans(n,vector<int>(m,0));
	    queue<Node> q;
	    
	   // init all starting points to q
	    for(int i = 0; i<n; i++){
	        for(int j = 0; j < m; j++){
	            if(grid[i][j] == 1){
                    pushToq(i,j,0,q);
	            }
	        }
	    }
	    
	    while(!q.empty()){
	        auto node = q.front();
	        q.pop();
	        
	        int i = node.i;
	        int j = node.j;
	        int step = node.step;
	        
	        if(vis[i][j] == 1) continue;
	        vis[i][j] = 1;
	        ans[i][j] = step;
	        
	        // add neighbours of (i,j) to q
	       if(i-1>=0 && vis[i-1][j] != 1) pushToq(i-1,j,step+1,q);
	       if(i+1<n && vis[i+1][j] != 1) pushToq(i+1,j,step+1,q);
	       if(j-1>=0 && vis[i][j-1] != 1) pushToq(i,j-1,step+1,q);
	       if(j+1<m && vis[i][j+1] != 1) pushToq(i,j+1,step+1,q);
	    }
	    return ans;
}