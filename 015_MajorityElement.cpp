#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {
	int ele = arr[0];
	int cnt = 1;

	for(int i =1; i<n; i++){
		if(cnt <= 0){
			cnt = 1;
			ele = arr[i];
			continue;
		}

		if(arr[i] == ele)cnt++;
		else cnt--;
	}

	cnt = 0;
	for(int i = 0; i < n; i++){
		if(arr[i] == ele) cnt++;
	}

	if(cnt > n/2) return ele;
	return -1;
}