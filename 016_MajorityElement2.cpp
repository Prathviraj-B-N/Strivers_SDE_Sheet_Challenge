#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr)
{
    int n = arr.size();
    int ele1 = -1;
    int cnt1 = 0;

    int ele2 = -1;
    int cnt2 = 0;

    for(auto x:arr){
        if(cnt1 == 0 && x != ele2){
            cnt1 = 1;
            ele1 = x;
        }else if(cnt2 == 0 && x != ele1){
            cnt2 = 1;
            ele2 = x;
        }
        else if(x == ele1) cnt1++;
        else if(x == ele2) cnt2++;
        else {
            cnt1--;
            cnt2--;
        }
    }

    cnt1 = 0;
    cnt2 = 0;

    for(auto x:arr){
        if(x == ele1) cnt1++;
        if(x == ele2) cnt2++;
    }

    vector<int> ans;
    if(cnt1 > n/3) ans.push_back(ele1);
    if(cnt2 > n/3) ans.push_back(ele2);

    return ans;
}