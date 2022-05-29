class Solution {
public:
    int minOperations(int n) {
      int x=n/2;  
      if(n%2==0) {
            return x*x;
        }
        else {
            return x*(x+1);
        }
    }
};