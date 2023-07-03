#include<algorithm>
string longestCommonPrefix(vector<string> &arr, int n)
{   
    if(n == 0) return "";
    if(n == 1) return arr[0];
    sort(arr.begin(),arr.end());
    int i = 0;
    int j = 0;

    int s = min(arr[n-1].size(),arr[0].size());
    string ans = "";
    while(i < s){
        if(arr[0][i] == arr[n-1][i]){
            ans.push_back(arr[0][i]);
            i++;
            j++;
            continue;
        }
        return ans;
    }
    return ans;
}