//Intition keep the end time as short as possible hence sort on tht 
class Solution {
public:
    static bool customComp(vector<int> a, vector<int> b){
        return a[1]< b[1];
    }
    int MaximumNonOverlappingIntervals(vector<vector<int>>& Intervals) {
        //your code goes here
        sort(Intervals.begin(), Intervals.end(), customComp);
        int n = Intervals.size();
        int remove =0;
        int lastTime = Intervals[0][1];
        for(int i=1;i<n;i++){
            if(Intervals[i][0]<lastTime){
                remove++;
            }else{
                lastTime = Intervals[i][1];
            }
        }
        return remove;
    }
};