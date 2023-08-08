vector<int> nextGreaterElement(vector<int>& arr, int n)
{
	vector<int> ans;
	stack<int> st;
	
	for(int i = n-1; i >= 0; i--){
		while((!st.empty()) && arr[i] >= st.top()) st.pop();
		
		if(st.empty() || st.top() <= arr[i]) ans.push_back(-1);
		else ans.push_back(st.top());

		if(st.empty() || st.top() > arr[i]) st.push(arr[i]);
	}
	reverse(ans.begin(),ans.end());
	return ans;
}

// 5 5 5 5 5
//       i
// 5
// -1  