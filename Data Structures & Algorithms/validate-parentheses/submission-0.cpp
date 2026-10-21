class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        unordered_map<char,char>mp;
        mp['}']='{';
        mp[')']='(';
        mp[']']='[';
        for(int i=0;i<s.length();i++){
            if(st.empty() || s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }
            else if(!st.empty() && st.top()!=mp[s[i]] ){
                return false;
            }
            else if(!st.empty() && st.top()==mp[s[i]]){
                st.pop();
            }
        }
        return st.empty();
    }
};
