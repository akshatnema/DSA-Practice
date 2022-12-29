class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        int n = piles.size();
        for(int i=0;i<n;i++){
            pq.push(piles[i]);
        }
        int j=0;
        while(j<k){
            int x= pq.top();
            pq.pop();
            x = x - (x/2);
            pq.push(x);
            j++;
        }
        int sum = 0;
        while(pq.size()>0){
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};