class Solution {
public:
    int divisorSubstrings(int num, int k) {
        int ct=0;
        string s=to_string(num);
        for(int i=0;i<s.length()-k+1;i++){
            string temp=s.substr(i,k);
            int num1=stoi(temp);
            if(num1!=0 && num%num1==0) ct++;
        }
        return ct;
    }
};