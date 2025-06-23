a// find the sorted half then nd move l nd r accordingly
// tc- o(logN)
class Solution {
public:
    int search(vector<int> &nums, int k) {
        int n = nums.size();
        int l = 0;
        int r = n-1;
        while(l<=r){
            int mid = (l+r)/2;
            if(nums[mid]==k) return mid;
            if(nums[l]<=nums[mid]){
                if(k>=nums[l] && k<=nums[mid]){
                    r = mid-1;
                }else{
                    l = mid+1;
                }

            }else{
                if(k<=nums[r] && k>=nums[mid]){
                    l = mid+1;
                }else{
                    r = mid-1;
                }
            }
            
        }
        return -1;
    }
};