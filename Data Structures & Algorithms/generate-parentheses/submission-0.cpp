class Solution {
public:
    void f(int n,vector<string> &v,string &temp,int op,int clo){
        if(clo==n){
            v.push_back(temp);
        }
        if(op>clo){
            temp+=')';
            f(n,v,temp,op,clo+1);
            temp.pop_back();
        }
        if(op<n){
            temp.push_back('(');
            f(n,v,temp,op+1,clo);
            temp.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string>v;
        string temp="";
        f(n,v,temp,0,0);
        return v;
    }
};
