class Solution {
public:
    vector<vector<int>> insertNewInterval(vector<vector<int>>& Intervals, vector<int>& newInterval){
        //your code goes here
        vector<vector<int>> ans;
        Intervals.push_back(newInterval);
        sort(Intervals.begin(), Intervals.end());
        int n = Intervals.size();

    
        int lastEndTime = Intervals[0][1];
        ans.push_back({Intervals[0][0], Intervals[0][1]});
        for(int i=1;i<n;i++){
            vector<int> lastval = ans.back();
            if(Intervals[i][0]<= lastval[1]){
                ans.pop_back();
                lastval[1] = max(lastval[1], Intervals[i][1]);
                ans.push_back(lastval);
            }else{
                ans.push_back(Intervals[i]);
            }
        }
        return ans;
    }
};