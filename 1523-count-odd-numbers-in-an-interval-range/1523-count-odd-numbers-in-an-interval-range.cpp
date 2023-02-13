class Solution {
public:
    int countOdds(int low, int high) {
        int n = (high - low)/2;
        if(high%2 || low %2) n++;
        return n;
    }
};