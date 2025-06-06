class Solution {
public:
    int partition(vector<int>& nums, int l, int r){

        int pi = nums[r];

        int start = l-1;

        for(int i=l;i<=r;i++){
            if(nums[i]< pi){
                start++;
                swap(nums[start],nums[i]);
            }
        }
        swap(nums[start+1], nums[r]);
        return start+1;
    }
    void quickSortHelper(vector<int>& nums, int l, int r){
        if(l>r){
            return;
        }
        int pi = partition(nums, l, r);
        quickSortHelper(nums, l, pi-1);
        quickSortHelper(nums, pi+1, r);

    }
    vector<int> quickSort(vector<int>& nums) {
        //partition first, mid, last or any random index and then move 
        // elements less than tht to left and more to the right.
        quickSortHelper(nums, 0, nums.size()-1);
        return nums;

    }
};
