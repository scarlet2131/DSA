//SJF TC - O(nlogn)+ o(n)
class Solution {
  public:
    long long solve(vector<int>& bt) {
        sort(bt.begin(), bt.end());
        long long n = bt.size();
        long long wait = 0;
        long long sum =0;
        for(long long i=0;i<n-1;i++){
            wait += bt[i];
            sum+= wait;
        }       
        return sum/bt.size();
    }
};