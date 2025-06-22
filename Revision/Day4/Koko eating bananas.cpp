// TC - O(N*log(maxEle))

class Solution {
public:
long long timeToEat(vector<int>& nums, int time){
    long long count =0;
    for(int i=0;i<nums.size();i++){
        double t = (double)nums[i]/ (double)time;
        count += ceil(t);
    }
    return count;

}
int minimumRateToEatBananas(vector<int> nums, int h) {
        int n = nums.size();
        int min=1, max= INT_MIN;
        for(int i=0;i<n;i++){
            if(nums[i]>max) max = nums[i];
        }
        int l = 1;
        int r = max;
        int ans=-1;
        while(l<=r){
            int mid = (l+r)/2;
            long long count = timeToEat(nums, mid);
            // when we get the ans we need to move behind to get the minimum ele
            if(count<=h){
                r = mid-1;
            }else{
                // the moment we get count > we move a step ahead so the last condition would the point
                // where i would have gotten the min count
                l = mid+1;   
            }
        }
        return l;
    }
};
