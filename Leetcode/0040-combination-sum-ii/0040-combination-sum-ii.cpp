class Solution {
public:
    vector<vector<int>> ans;
    void Findcombination(vector<int>& candidates, vector<int> &temp, int order, int target){
        if(target==0){
            ans.push_back(temp);
            return ;
        }else if(target<0) return ;
        else{
            for(int i=order;i<candidates.size();i++){
                if(candidates[i]>target) return ;
                if(i && candidates[i]==candidates[i-1] && i>order) continue;
                temp.push_back(candidates[i]);
                Findcombination(candidates, temp, i+1, target-candidates[i]);
                temp.pop_back();
            }
        }
    }
    
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {    
        int n=candidates.size();
        int sum=0;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        Findcombination(candidates, temp, 0, target);
        
        return ans;
    }
};