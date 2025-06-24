// Recursion tree( dry run)
// [] (sum=0)
// ├── [2] (2)
// │   ├── [2,2] (4)
// │   │   ├── [2,2,2] (6)
// │   │   │   ├── [2,2,2,2] (8) ❌
// │   │   │   └── [2,2,2,3] (9) ❌
// │   │   └── [2,2,3] (7) ✅
// │   └── [2,3] (5)
// │       └── [2,3,3] (8) ❌
// ├── [3] (3)
// │   ├── [3,3] (6)
// │   │   └── [3,3,3] (9) ❌
// │   └── [3,6] (9) ❌
// ├── [6] (6)
// │   └── [6,6] (12) ❌
// ├── [7] (7) ✅
// base condition and then traversal logic

class Solution {
public:
    void generatenumbers(vector<int>& candidates, int target, int l, vector<vector<int>>& ans, vector<int>& temp, int sum){
            if(sum==target ){
                ans.push_back(temp);
                return;
            }
            if( sum>target || l==candidates.size()) return;

            for(int i=l;i<candidates.size();i++){
                temp.push_back(candidates[i]);
                generatenumbers(candidates, target, i, ans, temp, sum+candidates[i]);
                temp.pop_back();
            }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       vector<vector<int>> ans;
       vector<int> temp;
       generatenumbers(candidates, target, 0, ans, temp, 0);
       return ans;
    }
};