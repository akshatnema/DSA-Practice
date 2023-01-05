//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
  public:
  bool isPrime(int num){
      if(num<2) return false;
      if(num==2) return true;
      if(num%2==0) return false;
      
      for(int i = 3;i<=sqrt(num);i+=2) {
          if(num%i==0) return false;
      }
      
      return true;
  }
  
    int shortestPath(int Num1,int Num2)
    {   
       if(Num1==Num2) return 0;
       queue<int> q;
       unordered_map<int, int> mp;
       mp[Num1]=0;
       q.push(Num1);
       while(q.size()){
           int x = q.front();
           q.pop();
           if(x==Num2) return mp[x];
           for(int i=1;i<=4;i++){
               int r = (x/(int)(pow(10, i-1)))%10*((int)(pow(10, i-1)));
               for(int j=0;j<=9;j++){
                  if(i==4 && j==0) continue;
                   int num = x - r;
                   num = num + j*(int)pow(10, i-1);
                //   if(num==Num2) return mp[x]+1;
                   if(isPrime(num) && !mp.count(num) && num >=1000 && num<=9999){ 
                       mp[num] = mp[x]+1;
                       q.push(num);
                       
                   }
               }
           }
       }
       return -1;
    }
};


//{ Driver Code Starts.
signed main()
{
    int t;
    cin>>t;
    Solution obj;
    while(t--)
    {
        int Num1,Num2;
        cin>>Num1>>Num2;
        int answer=obj.shortestPath(Num1,Num2);
        cout<<answer<<endl;
    }
}
// } Driver Code Ends