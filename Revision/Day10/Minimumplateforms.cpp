
// //At each point see how many trains have arreived at the station but not departed 
// and the ans will bne the maximum of tht number currnet trains at the station
class Solution{
    public:
    static bool customComparison(pair<int,int> a, pair<int,int> b){
        return a.second<b.second;
    }
    int findPlatform(vector<int>& Arrival, vector<int>& Departure){
        //your code goes here
        int n = Arrival.size();
        sort(Arrival.begin(), Arrival.end());
        sort(Departure.begin(), Departure.end());
        int ans =1;

        int i=0,j=0;
        int count =0;
        while(i<n && j<n){
            if(Arrival[i]<=Departure[j]){
                i++;
                count++;
            }else{
                j++;
                count--;
            }
            ans = max(ans, count);
        }
        return ans;
    }
};