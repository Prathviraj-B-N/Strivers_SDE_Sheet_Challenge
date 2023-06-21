bool isValidParenthesis(string expression)
{
    stack<char> st;
    for(auto x:expression){
        if(x == '}'){
            if(!st.size()) return false;
            if(st.top() == '{') st.pop();
            else return false;
        }
        else if(x == ')'){
            if(!st.size()) return false;
            if(st.top() == '(') st.pop();
            else return false;
        }
        else if(x == ']'){
            if(!st.size()) return false;
            if(st.top() == '[') st.pop();
            else return false;
        }
        else st.push(x);
    }
    if(st.size()) return false;
    return true;
}