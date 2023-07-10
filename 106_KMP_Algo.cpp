#include <bits/stdc++.h> 

void calculateLPS(vector<int>& lps, string& pattern){
    int len = 0;
    int i = 1;
    lps[0] = 0;

    int n = pattern.length();
    while(i < n){
        if(len == -1){
            lps[i] = 0;
            i++;
            len = 0;
            continue;
        }
        if(pattern[len] == pattern[i]){
            len++;
            lps[i] = len;
            i++;
        }else{
            len--;
        }
    }
}

bool findPattern(string p, string s)
{

    int i = 0;
    int j = 0;
    int psize = p.length();
    int ssize = s.size();
    
    vector<int> lps(psize,0);
    calculateLPS(lps,p);

    while(i < ssize){
        if(s[i] == p[j]){
            i++;
            j++;
            if(j == psize) return true;
        }else{
            if(j != 0) j = lps[j-1];
            else i = i+1;
        }

    }
    return false;

}