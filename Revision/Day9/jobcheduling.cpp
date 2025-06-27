// the logic intuution comes from thinking if there is a deadline and do tht task at the last moment 
// menas we have kept space in the beginning for other tasks to get done as much as possible

class Solution{  
  public:  
    static bool customcomp(pair<int,int> a, pair<int,int> b){
        return a.second > b.second ;
    }
    vector<int> JobScheduling(vector<vector<int>>& Jobs) { 
        //your code goes here
        int n = Jobs.size();
        vector<pair<int,int>> timetable;
        int maxDeadline = 0;
        for(int i=0;i<n;i++){
            if(Jobs[i][1]>maxDeadline) 
                maxDeadline = Jobs[i][1];
            timetable.push_back({Jobs[i][1], Jobs[i][2]});
        }

        sort(timetable.begin(), timetable.end(), customcomp);
        int jobs= 0;
        int totaltime = 0;
        vector<int> finishTimeline(maxDeadline+1, -1);
        for(int i=0;i<n;i++){
            if(finishTimeline[timetable[i].first]==-1){
                finishTimeline[timetable[i].first] = 1;
                jobs++;
                totaltime += timetable[i].second;
            }else{
                for(int j=timetable[i].first;j>0;j--){
                    if(finishTimeline[j]==-1){
                        finishTimeline[j]=1;
                        jobs++;
                        totaltime += timetable[i].second;
                        break;
                    }
                }
            }
           
        }
        
        return {jobs, totaltime};
    } 
};