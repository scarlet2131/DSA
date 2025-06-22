//Edge case is figuring out the sorted half 
// because in this case we can have duplicates
// what if arr[mid]==arr[l]==arr[r] all same 
// we cant deceide which is sorted then we will 
// just reduce the serahc space by l++, r--;
class Solution {
public:
    bool searchInARotatedSortedArrayII(vector<int> &nums, int k)  {
        int n = nums.size();
        int l =0, r=n-1;
        while(l<=r){
            int mid = (l+r)/2;
            if(nums[mid] == k){
                return true;
            }
            if(nums[l]==nums[mid] && nums[mid]==nums[r]){
                l++;
                r--;
                continue;
            }
            if(nums[l]<=nums[mid]){
                if(k>=nums[l] && k<=nums[mid]){
                    r = mid -1;
                }else{
                    l = mid+1;
                }

            }else{

                if(k<=nums[r] && k>=nums[mid] ){
                    l = mid+1;
                }else{
                     r= mid-1;
                }

            }
        }
        return false;
    }
};