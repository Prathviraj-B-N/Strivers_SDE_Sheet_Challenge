#include <bits/stdc++.h> 

void sol(stack<int> &st){
	if(st.size()==1) return;
	int cur = st.top();
	st.pop();
	sol(st);
	if(cur < st.top()){
		int temp = st.top();
		st.pop();
		st.push(cur);
		st.push(temp);
		sol(st);
	}else{
		st.push(cur);
	}

}

void sortStack(stack<int> &stack)
{
	sol(stack);

}

