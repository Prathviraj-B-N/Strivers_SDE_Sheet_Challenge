// O(n)
int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) {
    int cnt = 0;
    int l = 0;
    int r = 0;
    int ans;
    while(cnt < k && l < m && r < n){
        if(row1[l] <= row2[r]){
            ans = row1[l++];
        }else{
            ans = row2[r++];
        }
        cnt++;
    }

    if(cnt < k && l < m) return row1[l+(k-cnt-1)];
    if(cnt < k && r < n) return row2[r+(k-cnt-1)];

    return ans;
}

// O(log(min(m,n)))
#include<bits/stdc++.h>
int ninjaAndLadoos(vector<int> &a, vector<int> &b, int m, int n, int k) {
    
    if(m > n) return ninjaAndLadoos(b, a, n, m, k);
    // we have smaller arr on left
    // to form k we choose 2 numbers a+b = k
    // a can be max(0,k-n) to min(k,m) then b will be k-a;

    int l = max(0,k-n);
    int h = min(k,m);

	while(l <= h){
		int cut1 = (l+h) >> 1;
		int cut2 = k - cut1;

		int l1 = (cut1 == 0)? INT_MIN : a[cut1-1];
 		int l2 = (cut2 == 0)? INT_MIN : b[cut2-1];

		int r1 = (cut1 == m)? INT_MAX : a[cut1];
 		int r2 = (cut2 == n)? INT_MAX : b[cut2];

		if(l1 <= r2 && l2 <= r1){
			return max(l1,l2);
		}
		else if(l1 > r2) h = cut1 - 1;
		else l = cut1 + 1;
	}
    return -1;
}