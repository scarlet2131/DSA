//the only differnece is we store the index of the first occurance of the sum whenever found to get
// the maximum sum 
class Solution{
public:
    int longestSubarray(vector<int> &nums, int k){
        map<int,int> mp;
        int sum=0;
        int ans=0;
        // mp[0]=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum==k) ans = max(ans, i+1);
            
            if(mp.find(sum-k)!=mp.end()){
                ans = max( ans, i-mp[sum-k]);
            }
            
            if(mp.find(sum)==mp.end()){
                 mp[sum] = i;
            }
           
        }
        return ans;
    }
};
