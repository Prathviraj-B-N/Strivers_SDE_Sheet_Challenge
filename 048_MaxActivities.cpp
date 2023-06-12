#include<bits/stdc++.h>
typedef struct{
    int start;
    int end;
} activity;

bool cmp(activity a,activity b){
    if(a.end < b.end) return true;
    if(a.end > b.end) return false;
    return (a.start < b.start);
}

int maximumActivities(vector<int> &start, vector<int> &finish) {
    activity a[start.size()];
    int n = start.size();

    for(int i = 0; i < n; i++){
        a[i].start = start[i];
        a[i].end = finish[i];
    }

    sort(a,a+n,cmp);

    int curEnd = a[0].end;
    int count = 1;

    for(int i = 1 ; i < n; i++){
        if(a[i].start >= curEnd){
            curEnd = a[i].end;
            count++;
        }
    }

    return count;
}