double median(vector<int>& a, vector<int>& b) {
	int n1 = a.size();
	int n2 = b.size();

	if(n2 < n1) return median(b, a);

	int l = 0;
	int h = n1;
	int n = n1+n2;

	while(l <= h){
		int cut1 = (l+h) >> 1;
		int cut2 = ((n + 1) / 2) - cut1; // +1 to handle odd

		int l1 = (cut1 == 0)? INT_MIN : a[cut1-1];
 		int l2 = (cut2 == 0)? INT_MIN : b[cut2-1];

		int r1 = (cut1 == n1)? INT_MAX : a[cut1];
 		int r2 = (cut2 == n2)? INT_MAX : b[cut2];

		if(l1 <= r2 && l2 <= r1){
			if(n % 2) return max(l1,l2);
			return (max(l1,l2)+min(r1,r2)) / 2.0;
		}
		else if(l1 > r2) h = cut1 - 1;
		else l = cut1 + 1;
	}

	return 0;
}