class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack <char> s1;
        for(int i=0;i<s.length();i++){
            if(s[i]=='#'){
                if(!s1.empty())
                    s1.pop();
                continue;
            }
            s1.push(s[i]);
        }
        s="";
        while(!s1.empty()) {
            s+=s1.top();
            s1.pop();
        }

        for(int i=0;i<t.length();i++){
            if(t[i]=='#'){
                if(!s1.empty())
                    s1.pop();
                continue;
            }
            s1.push(t[i]);
        }
        t="";
        while(!s1.empty()) {
            t+=s1.top();
            s1.pop();
        }
        // cout<<s<<endl;
        // cout<<t<<endl;
        if(s==t)
            return true;
        else return false;
    }
};