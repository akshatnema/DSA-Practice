class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> fre1(n, 0);
        vector<int> fre2(n, 0);
        for(int i=0;i<trust.size();i++){
            fre1[trust[i][0]-1]++;
            fre2[trust[i][1]-1]++;
        }
        for(int i=0;i<n;i++){
            if(fre1[i]==0 && fre2[i]==n-1){
                return i+1;
            }
        }
        return -1;
    }
};