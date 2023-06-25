#include<bits/stdc++.h>
string reverseString(string &str){
	string temp = "";
	stack<string> st;
	for(auto x:str){
          if (x == ' ') {
            if (temp.size() != 0) {  
			  	st.push(temp);
				temp = "";
			}
            continue;
          }
		  temp+=x;
    }
	
	if(temp != "") st.push(temp);

	string ans ;
	while(!st.empty()){
		ans+=st.top();
		st.pop();
		ans.push_back(' ');
	}

	return ans;
}