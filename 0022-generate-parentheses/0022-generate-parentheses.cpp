class Solution {
public:
    vector<string> ans;
    void rec(int i, stack<char> s, string &temp){
        if(i==0){
            int n=s.size();
            for(int i=0;i<n;i++)
                temp.push_back(')');
            ans.push_back(temp);
            for(int i=0;i<n;i++)
                temp.pop_back();
            return ;
        }
        
        
        temp.push_back('(');
        s.push('(');
        rec(i-1, s, temp);
        temp.pop_back();
        s.pop();
        if(!s.empty()){
            temp.push_back(')');
            s.pop();
            rec(i, s, temp);
            temp.pop_back();
            s.push('(');
        }
        return ;
    }
    
    vector<string> generateParenthesis(int n) {
        stack<char> s;
        string temp;
        rec(n, s, temp);
        return ans;
    }
};