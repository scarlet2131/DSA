class Solution {
public:

    void merge(vector<int>& nums, int left, int right, int mid){
       int n1 = mid-left+1;
       int n2 = right - (mid+1)+1;
       vector<int> nums1(n1);
       vector<int> nums2(n2);

       for(int i=0;i<n1;i++){
        nums1[i] = nums[left+i];
       }
       for(int i=0;i<n2;i++){
        nums2[i] = nums[mid+1+i];
       }
       int l1 =0, l2=0;
       int k=left;
       while(l1<n1 && l2<n2){
        if(nums1[l1]> nums2[l2]){
            nums[k] = nums2[l2];
            l2++;
        }else{
            nums[k] = nums1[l1];
            l1++;
        }
        k++;
       }

       while(l1<n1){
         nums[k] = nums1[l1];
            l1++;
            k++;

       }

       while(l2<n2){
         nums[k] = nums2[l2];
            l2++;
            k++;
       }
    }
    void mergeSortHelper(vector<int>& nums, int l, int r){
        if(l>=r){
            return ;
        }
        int mid = (l+r)/2;
    
        mergeSortHelper(nums, l , mid);
        mergeSortHelper(nums, mid+1, r);
        merge(nums, l, r, mid);
    }
    vector<int> mergeSort(vector<int>& nums) {
        mergeSortHelper(nums,0,nums.size()-1);
        return nums;
    }
};
