class Solution {
public:
    int characterReplacement(string s, int k) {
        char c;
        vector <int> v(26,0);
        deque<char> dq;
        int ct=0,ans=-1;
        for(int j=0;j<26;j++){
            c=(char)('A'+j);
            ct=0;
            dq.clear();
          for(int i=0;i<s.length();i++){
            if(s[i]!=c){
                if(ct<k){
                    dq.push_back(s[i]);
                    ct++;
                }else{
                    ans=max(ans,(int)dq.size());
                    while(!dq.empty() && dq.front()==c)
                        dq.pop_front();
                    dq.pop_front();
                    dq.push_back(s[i]);
                }
                    
            }else{
                dq.push_back(s[i]);
            }
            ans=max(ans,(int)dq.size());
        }
    }
        return ans;
    }
};