class Solution {
public:
    bool isPalindrome(string s) {
        string temp;
        for(int i=0;i<s.length();i++){
            if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))
                temp+=tolower(s[i]);
            if(s[i]>='0' && s[i]<='9')
                temp+=s[i];
        }
        string temp1=temp;
        reverse(temp1.begin(),temp1.end());
        if(temp==temp1) return true;
        else return false;
    }
};