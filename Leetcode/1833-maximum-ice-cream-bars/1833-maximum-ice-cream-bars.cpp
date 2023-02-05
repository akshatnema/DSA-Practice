class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int ans=0, amt=0;
        for(int i=0;i<costs.size();i++){
            if(amt+costs[i]>coins) return ans;
            ans++;
            amt+=costs[i];
        }
        return ans;
    }
};