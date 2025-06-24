// for all unique answers we only need to sort the candidates  array
// and also make sure to not call the rrcsuion with same number 

class Solution {
public:
    void generate(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& temp, int l, int sum){
        if(sum==target){
            ans.push_back(temp);
            return;
        }
        if(sum>target || l>candidates.size()) return;
        for(int i=l;i<candidates.size();i++){
            if(i>l && candidates[i]==candidates[i-1]) continue;
            temp.push_back(candidates[i]);
            generate(candidates, target, ans, temp, i+1, sum+ candidates[i]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        generate(candidates,target, ans, temp, 0,0);
        return ans;
    }
};