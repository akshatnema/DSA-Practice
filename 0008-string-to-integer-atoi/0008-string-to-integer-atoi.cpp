class Solution {
public:
    int myAtoi(string s) {
        int flag=0, ispos=0; long long int ans=0;
        for(int i=0;i<s.length();i++){
            if(s[i]>='0' && s[i]<='9'){
                flag=1;
                ans = ans*10 + s[i]-'0';
                if(ispos){
                    if(-ans<=INT_MIN){
                        ans=INT_MIN;
                        break ;
                    }
                }else{
                    if(ans>=INT_MAX){
                        ans=INT_MAX;
                        break;
                    }
                }
            }else if(s[i]==' '){
                if(flag) break;
                else continue ;
            }else if((s[i]=='-' || s[i]=='+') && flag==0){
                flag=1;
                if(s[i]=='-') ispos=1;
            }
            else break;
        }
         // cout<<INT_MIN<<" "<<INT_MAX<<endl;
        if(ispos && ans!=INT_MIN){
           ans=-ans;
        }
        return ans;
    }
};