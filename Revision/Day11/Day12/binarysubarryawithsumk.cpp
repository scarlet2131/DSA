// hash map approach with extra space 
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int k) {
        //your code goes here
        map<int,int> mp;
        int sum=0;
        int ans=0;
        mp[0]=1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(mp.find(sum-k)!=mp.end()){
                ans+= mp[sum-k];
            }
             mp[sum]++;
           
        }
        return ans;
        
    }
};
//optimal 



class Solution {
public:
    int countSubarrays(vector<int>& nums, int k){
        int count =0, sum=0;
        int l=0,r=0;
        int n = nums.size();
         if(k<0) return 0;

        while(r<n){
          sum += nums[r];
         
          while(sum>k){
               sum-=nums[l];
               l++;
          }
          count += (r-l+1);
          r++;


        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int k) {
        return countSubarrays(nums,k) - countSubarrays(nums,k-1);
        
    }
};
