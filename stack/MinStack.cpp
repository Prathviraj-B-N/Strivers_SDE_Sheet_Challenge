// learning: stack.top() can hold some data about current state of the stack. we use pair to store more than one value
class MinStack{
    private:
        stack<pair<int,int>> st;
    public:
        void push(int x){
            int new_min = st.empty()? x: min(st.top().second,x);
            st.push({x,new_min});
            cout<<"pushed "<<x<<" "<<new_min<<"\n";
        }
        
        void pop(){
            auto cur = st.top();
            if(!st.empty()){
                st.pop();
            }
            cout<<"popped "<<cur.first<<"\n";
            return cur.first;
        }
        
        void min_ele(){
            if(st.empty()) cout<<-1<<"\n";
            cout<<"min_ele"<<st.top().second<<"\n";
        }
};

int main()
{
    
    MinStack st;
    
    st.push(5);
    st.min_ele();
    st.push(1);
    st.min_ele();
    st.push(3);
    st.min_ele();
    st.pop();
    st.min_ele();
    st.pop();
    st.min_ele();
    st.pop();
    st.min_ele();
    
    return 0;
}
