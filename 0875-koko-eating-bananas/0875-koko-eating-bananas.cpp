class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int l = 1, r=piles[piles.size()-1];
        while(l<=r){
            int mid=(l+r)/2;
            long long int hour=0;
            for(int i=0;i<piles.size();i++){
                hour+=piles[i]/mid;
                if(piles[i]%mid) hour++;
            }
            if(hour>h){
                l=mid+1;
            }else r=mid-1;
        }
        return l;
    }
};