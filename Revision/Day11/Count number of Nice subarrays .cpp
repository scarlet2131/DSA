class Solution {
public:
    int countSubarrays(vector<int>& nums, int k){
        int n = nums.size();
        int l=0,r=0;
        int odd=0, count=0;

        while(r<n){
            if(nums[r]%2!=0) odd++;
            while(odd>k){
                if(nums[l]%2!=0) odd--;
                l++;
            }
            count += r-l+1;
            r++;
        }
        return count;
    }
    int numberOfOddSubarrays(vector<int>& nums, int k) {
        return countSubarrays(nums,k)- countSubarrays(nums,k-1);
    }
};