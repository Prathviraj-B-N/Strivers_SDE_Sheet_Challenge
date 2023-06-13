string kthPermutation(int n, int k) {
    int fact = 1;
    
    //n-1 factorial
    for(int i = 1; i < n;i++) fact *= i ;
    
    string s = "";
    string ans = "";

    for(int i = 1; i <= n;i++) s.push_back('0'+i);
    
    k -= 1;
    while(s.size() > 0){
        ans += s[k/fact];
        s.erase(s.begin()+k/fact);
        if(s.size() == 0) break;
        
        k = k%fact;
        fact = fact / s.size();
    }

    return ans;
    
}
