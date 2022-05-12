class Solution {
public:
   static bool cnp(pair<string,string> a, pair<string,string> b){
        return a.first<b.first;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       int n=strs.size();
        vector<pair<string,string>> vp(n);
        for(int i=0;i<n;i++){
            vp[i].second=strs[i];
            sort(strs[i].begin(),strs[i].end());
            vp[i].first=strs[i];
        }
        sort(vp.begin(),vp.end(),cnp);
        vector<vector<string>> ans;
        vector<string> temp;
        temp.push_back(vp[0].second);
        string ini=vp[0].first;
        for(int i=1;i<n;i++){
            if(ini!=vp[i].first){
                ans.push_back(temp);
                temp.clear();
                ini=vp[i].first;
                temp.push_back(vp[i].second);
            }else{
                temp.push_back(vp[i].second);
            }
        }
      ans.push_back(temp);
        return ans;
    }
};