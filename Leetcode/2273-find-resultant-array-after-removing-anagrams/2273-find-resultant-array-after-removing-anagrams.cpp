class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector <string> ans;
        vector <string> sorted(words.size());
        for(int i=0;i<words.size();i++){
            string temp=words[i];
            sort(temp.begin(), temp.end());
            sorted[i]=temp;
        }
        ans.push_back(words[0]);
        for(int i=1;i<words.size();i++){
            if(sorted[i]!=sorted[i-1])
                ans.push_back(words[i]);
        }
        return ans;
    }
};