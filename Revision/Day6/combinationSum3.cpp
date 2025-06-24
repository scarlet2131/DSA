//small tweek tht the no of elements is also fixed now 
class Solution {
public:
    void generate(vector<int>& candidates, int target,int n, vector<vector<int>>& ans, vector<int>& temp, int l, int sum){
        if(sum==target && temp.size()==n){
            ans.push_back(temp);
            return;
        }
        if(sum>target || temp.size()>n) return;
        for(int i=l;i<candidates.size();i++){
            temp.push_back(candidates[i]);
            generate(candidates, target,n, ans, temp, i+1, sum+ candidates[i]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<int> candidates = {1,2,3,4,5,6,7,8,9};
        generate(candidates,n,k, ans, temp, 0,0);
        return ans;
        
    }
};