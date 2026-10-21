class MinStack {
    vector<int>st;
public:
    MinStack() {}
    
    void push(int val) {
        st.push_back(val);
    }
    
    void pop() {
        if(st.size()){
            st.pop_back();
        }
    }
    
    int top() {
        int n=st.size();
        if(n>0){
            return st[n-1];
        }
    }
    
    int getMin() {
        int ans=INT_MAX;
        for(int i=0;i<st.size();i++){
            ans=min(ans,st[i]);
        }
        return ans;
    }
};
