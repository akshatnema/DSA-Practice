class Solution {
public:
    int reverse(int x) {
        long long int ans = 0;
        int n=abs(x);
        while(n!=0){
            ans = ans*10 + n%10;
            n=n/10;
        }
        if(x<0) ans = -ans;
        if(ans>pow(2,31)-1 || ans<-pow(2,31))
            return 0;
        return ans;
    }
};