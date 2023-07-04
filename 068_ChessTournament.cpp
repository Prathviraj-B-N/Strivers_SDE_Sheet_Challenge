#include <bits/stdc++.h> 

bool check(vector<int>& roomPosition,int gap,int numPlayers){

    int prevPlayerPos = roomPosition[0];
    int playerCount  = 1;
    int n = roomPosition.size();

    for(int i=1; i < n; i++){
        if(roomPosition[i] -  prevPlayerPos < gap) continue;
        playerCount++;
        prevPlayerPos = roomPosition[i];
        if(playerCount == numPlayers) return true;
    }
    return false;
}


int chessTournament(vector<int> positions , int n ,  int c){
    sort(positions.begin(), positions.end());

    int l = 1;
    int r = positions[n-1];
    int ans = -1;

    while(l<=r){
        int gap = l+(r-l)/2;
        // can we place c players in rooms(positions[]) maintaining gap
        if(check(positions,gap,c)){
            // try increasing gap but save cur res
            ans = gap;
            l = gap+1;
        }else{
            // reduce gap and try again
            r = gap-1;
        }
    }
    return ans;

}

/*
    c players
    n free rooms
    focus = min dist bw his room and another player
    
    for player p focus = min dist bw p,p-1 and p,p+1
    tournament foocus = min focus lvl among all players
    maximize tournament focus -> place players as far as possible

    int l = 1; min distance is 0
    int r = pos[n-1]; max distance is placing players at opposite ends

    finding somethin in a range ; classic binary search problem
*/