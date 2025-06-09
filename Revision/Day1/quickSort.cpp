
// taking first as pivot 
class Solution {
public:
    int partition(vector<int>& nums, int l, int r){

        int pi = nums[l];

        int start = l+1;

        for(int i=l+1;i<=r;i++){
            if(nums[i] < pi){
                swap(nums[start],nums[i]);
                start++;
            }
        }
        swap(nums[start-1], nums[l]);
        return start-1;
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


//taking last as pivot
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


//taking random number as random index
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
    int partition_r(vector<int>& nums, int l , int r){

       int random =  l + (rand() % (r - l + 1));
       swap(nums[random],nums[r]);
       return partition(nums, l, r);
    }
    void quickSortHelper(vector<int>& nums, int l, int r){
        if(l>r){
            return;
        }

        //partition 
        int pi = partition_r(nums, l, r);
        quickSortHelper(nums, l, pi-1);
        quickSortHelper(nums,pi+1, r);
    }
    vector<int> quickSort(vector<int>& nums) {
        //choose first
        quickSortHelper(nums,0,nums.size()-1);
        return nums;

    }
};




