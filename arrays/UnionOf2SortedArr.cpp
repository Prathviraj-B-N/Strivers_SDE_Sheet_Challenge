vector < int > sortedArray(vector < int > a, vector < int > b) {
    int i = 0;
    int j = 0;
    int n = a.size();
    int m = b.size();
    vector<int> ans;
    
    while(i < n && j < m){
        if(a[i] == b[j]){
            ans.push_back(a[i]);
            i++;
            while(a[i] == a[i-1]) i++;
            j++;
            while(b[j] == b[j-1]) j++;
        }else if (a[i] < b[j]){
            ans.push_back(a[i]);
            i++;
            while(a[i] == a[i-1]) i++;
        }else{
            ans.push_back(b[j]);
            j++;
            while(b[j] == b[j-1]) j++;
        }
    }
    
    while(i < n){
        ans.push_back(a[i]);
        i++;
        while(a[i] == a[i-1]) i++;
    }

    while(j < m){
        ans.push_back(b[j]);
        j++;
        while(b[j] == b[j-1]) j++;
    }

    return ans;
}


//                 i
// 1 2 2 2 3 3 3 4 5 6
// 2 2 3 4 4 4 4
//               j
 
// 1 2 3 4