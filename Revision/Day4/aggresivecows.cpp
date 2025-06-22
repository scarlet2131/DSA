// bruteforce to find the cows assume you know the distance to make then sit 
// o(n**2)

class Solution {
public:
    bool ispossible(vector<int>& nums, int dist, int k){
        int count = 1;
        int cows = 1;
        int l = 1;
        int diff = 0;
        while(l<nums.size()){
            diff += nums[l]-nums[l-1];
            if(diff>=dist){
                cows++;
                diff = 0;
            }
            l++;
        }
        return cows>=k ? true : false;
    }
    int aggressiveCows(vector<int> &nums, int k) {
        int ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i=1;
        int maxi = nums[n-1]-nums[0];
        for(int j=i;j<=maxi;j++){
            if(ispossible(nums, j, k)){
                ans = j;
            }else{
                break;
            }
        }
        return ans;
    }
};


// Optimal - applying binary search for the l and r part  TC- o(nlog(maxdiff(max-min)))

class Solution {
public:
    bool ispossible(vector<int>& nums, int dist, int k){
        int count = 1;
        int cows = 1;
        int l = 1;
        int diff = 0;
        while(l<nums.size()){
            diff += nums[l]-nums[l-1];
            if(diff>=dist){
                cows++;
                diff = 0;
            }
            l++;
        }
        return cows>=k ? true : false;
    }
    int aggressiveCows(vector<int> &nums, int k) {
        int ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int l=1;
        int r = nums[n-1]-nums[0];
        
        while(l<=r){
            int mid = (l+r)/2;
            // cout<<mid<<endl;
            if(ispossible(nums, mid, k)){
                ans = mid;
                l = mid +1;
            }else{
                r = mid-1;
            }

        }
        return ans;
    }
};