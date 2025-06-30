//Bruteforce - o(nlogn + o(n))
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


// Without sorting because the intervals are already sorted and non overlapping so first find the point
// of insertion for newinterval and then insert the new intervals making sure merging all the pointin between
// intervals and then at the end adding the rest of the non overlapping intervals 

class Solution {
public:
    vector<vector<int>> insertNewInterval(vector<vector<int>>& Intervals, vector<int>& newInterval){
        //your code goes here
        vector<vector<int>> ans;
        int l=0;
        int n = Intervals.size();
        while(l<n && Intervals[l][1]< newInterval[0]){
          ans.push_back(Intervals[l]);
          l++;
           
        }
        
        while(l<n && Intervals[l][0]<= newInterval[1]){
           newInterval[0] = min(Intervals[l][0], newInterval[0]);
           newInterval[1] = max(Intervals[l][1], newInterval[1]);
           l++; 
        }
        ans.push_back(newInterval);
        while(l<n){
            ans.push_back(Intervals[l]);
            l++;
        }
        return ans;
    
    }
};