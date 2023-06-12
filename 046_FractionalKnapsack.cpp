#include <bits/stdc++.h> 
bool cmp(pair<int, int> a, pair<int, int> b){
    return (((double)a.second/a.first) > ((double)b.second/b.first));
}

double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.

    sort(items.begin(),items.end(),cmp);
    int curW = 0;
    double ans = 0;

    for(int i = 0; i < n ; i++){
        if(curW >= w ) break;

        if(items[i].first <= (w-curW)){
            curW += items[i].first;
            ans += items[i].second;
        }else{
            ans+= (double)(w-curW)*(double)((double)items[i].second/(double)items[i].first);
            break;
        }
    }

    return ans;

}