class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> sell(prices.size(),0);
        int mx=-1;
        for(int i=prices.size()-1;i>=0;i--){
            if(i==prices.size()-1){
                mx=max(mx,prices[i]);
                sell[i]=0;
                continue;
            }
            sell[i]=mx;
            mx=max(mx,prices[i]);
        }
        int ans=0;
        for(int i=0;i<prices.size();i++){
            ans=max(ans,sell[i]-prices[i]);
        }
        return ans;
    }
};