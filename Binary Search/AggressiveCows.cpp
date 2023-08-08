bool check(vector<int> &stalls,int distance,int cows){

    int count = 1;
    int prev = stalls[0];

    for(int i = 1;i < stalls.size(); i++){
        if(stalls[i] - prev >= distance){
            count++;
            prev = stalls[i];
        }
        if(count == cows) return true;
    }

    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    int l = 1;
    int h = 1e9;
    sort(stalls.begin(),stalls.end());
    while(l<=h){
        int mid = l+(h-l)/2;
        if(check(stalls,mid,k)){
            l = mid+1;
        }else{
            h = mid-1;
        }
    }
    return h;
}