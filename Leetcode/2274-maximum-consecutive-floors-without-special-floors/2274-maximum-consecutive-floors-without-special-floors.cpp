class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(),special.end());
        int mx=0;
        mx=max(mx, special[0]-bottom);
        for(int i=1;i<special.size();i++)
        {
            mx=max(special[i]-special[i-1]-1, mx);
        }
        mx=max(mx, top-special[special.size()-1]);
        return mx;
    }
};