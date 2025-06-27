//meeting which ends early is will free the room sooner for more meetings to happen so we will sort on the basis 
// of end time
class Solution{
    public:
    static bool customComp(pair<int,int> a, pair<int,int> b){
        return a.second < b.second;
    }
    int maxMeetings(vector<int>& start, vector<int>& end){
        //your code goes here
        int n = start.size();
        vector<pair<int,int>> timetable;
        for(int i=0;i<n;i++){
            timetable.push_back({start[i], end[i]});
        }
        sort(timetable.begin(), timetable.end(), customComp);

     
        int meetCount = 1;
        int lastmeet = 0;
        for(int i=1;i<n;i++){
            if(timetable[i].first > timetable[lastmeet].second){
                lastmeet = i;
                meetCount++;
            }
        }
        return meetCount;
    }
};