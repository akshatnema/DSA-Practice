class Solution {
public:
    
    double power(double x, int n) {
        if(n==0) return 1;
        else if(n==1) return x;
        else {
            if(n%2) {
                return pow(power(x, n/2), 2)*x;
            } else 
                return pow(power(x, n/2), 2);
        }
    }
    
    double myPow(double x, int n) {
        if(x==1) {
            return 1;
        } else if(x==-1) {
            return n%2 ? -1 : 1;
        } else {}
        long n1=n;
        if(n1<0) {
            x=1/x;
            n1=-n1;
        }
        return power(x, n);
    }
};