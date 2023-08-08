bool rotateString(string s, string goal) {
    string ss = s+s;
    int m = ss.size();

    int i = 0;
    int j = 0;

    if(s.length() != goal.length()) return false;
    
    while(i < m && j < goal.length()){
        if(ss[i] == goal[j]){
             i++;
             j++;
        }else{
            if(j==0) i++;
            else j = 0;
        }
        
    }

    return j == goal.length();
}