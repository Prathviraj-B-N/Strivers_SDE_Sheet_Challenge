#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    if(n <= 1) return permutation;
    int i = 0;

    for(i = n-2; i >= 0; i--){
        if(permutation[i] < permutation[i+1]) break;
    }

    // now i found the position where i can divide the array
    // if i == -1 then answer is reverse from 0 to n-1
    // this gives us hint that what if we sort everything from i+1 to n-1
    // and what to do with i ? swap with next greater element within (i+1 to n)
    
    if(i != -1){
        for (int j = n - 1; j > i; j--) {
            if (permutation[j] > permutation[i]){
                swap(permutation[i], permutation[j]);
                break;   
            }
        }
    }

    // sort i+1 to n
    sort(permutation.begin()+i+1, permutation.end());
    return permutation;
}

/*
    n integers, 1 - n exactly once
    find next greater permutation
    
    lexicographically smaller means:

    for i = 0 to n-1:
        if a[i] == b[i] continue
        if a[i] < b[i] a is smaller
        else b is smaller 

    we have to find next greater permutation

    1 2 3 4
    1 2 4 3
    1 3 2 4
    1 3 4 2
    1 4 2 3
    1 4 3 2

    2 1 3 4 <- i-1 is less than i ; so there is a scope of swap
    2 1 4 3 ans
    2 3 1 4
    2 3 4 1
    2 4 1 3
    2 4 3 1

    3 1 2 4
    3 1 4 2
    3 2 1 4
    3 2 4 1
    3 4 1 2
    3 4 2 1

    4 1 2 3
    4 1 3 2
    4 2 1 3
    4 2 3 1
    4 3 1 2
    4 3 2 1

    
    we have to check from last
    [ 1, 3, 7, 4, 2] 
    [ 1, 3, ]


*/