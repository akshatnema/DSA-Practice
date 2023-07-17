class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mi=INT_MAX, ans = INT_MIN;
        for(int i=0;i<prices.size();i++) {
            mi = min(mi, prices[i]);
            ans = max(ans, prices[i] - mi);
        }
        return ans;
    }
};