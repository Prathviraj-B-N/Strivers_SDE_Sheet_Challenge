#include <bits/stdc++.h> 

typedef struct meets{
    int start;
    int end;
    int pos;
} meet;

bool cmp(meet a, meet b){
    if(a.end == b.end && a.pos < b.pos) return true;
    return (a.end < b.end) ;
}

vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    int n = start.size();
    meet m[n];

    for(int i = 0; i < n ; i++){
        m[i].start = start[i];        
        m[i].end = end[i];
        m[i].pos = i+1;
    }

    sort(m, m+n, cmp);

    vector<int> ans;
    int curEnd = m[0].end;
    ans.push_back(m[0].pos);
    
    for(int i = 1; i<n; i++){
        if(m[i].start > curEnd){
            curEnd = m[i].end;
            ans.push_back(m[i].pos);
        }
    }

    return ans;
    
}